/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_CREATE_IMAGE.C                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   BY: PFAUST <MARVIN@42.FR>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   CREATED: 2018/01/10 14:44:01 BY PFAUST            #+#    #+#             */
/*   Updated: 2018/01/25 13:37:22 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void		diago_montant(t_env *env, int x, int y, int new_origin)
{
	int		k;
	int		vector;

	k = 0;
	while (k < env->scale * env->matrix[y][x + 1] && y - k >= 0 )
	{
		if ((vector = new_origin + ((x + k) * env->scale) + (((y - k) * env->scale) * env->width)) >=  0)
		{
			printf("MONTANT z : %d z_next : %d, k: vector : %d\n", env->matrix[y][x] , env->matrix[y][x + 1] , vector);
			env->data_addr[vector] = mlx_get_color_value(env->mlx, 0x00FFFFFF);
		}
		//printf("%5d", new_origin + (x * env->scale) + ((y * env->scale) * env->width) + k);
		k++;
	}

}
void		diago_descendant(t_env *env, int x, int y, int new_origin)

{
	int		k;
	int		vector;

	k = 0;
	while (k < env->scale * env->matrix[y][x + 1] && y - k >= 0 )
	{
		if ((vector = new_origin + ((x + k) * env->scale) + (((y + k) * env->scale) * env->width)) >=  0)
		{
			printf("DESCENDANT z : %d z_next : %d, k: vector : %d\n", env->matrix[y][x] ,env->matrix[y + 1][x] , vector);
			env->data_addr[vector] = mlx_get_color_value(env->mlx, 0x00FFFFFF);
		}
		//printf("%5d", new_origin + (x * env->scale) + ((y * env->scale) * env->width) + k);
		k++;
	}
}

void		ft_display_coords(t_env *env)
{	
	int		z;
	int		z_next;
	int		x;
	int		y;
	int		k;
	int		m;
	int		vector;;
	int		y_prime;
	int		**modified_matrix;
	int		new_origin;
	unsigned int color[100] = {0x00808080,0x00FFFFFF}; 

	printf("WIDTH : %d\n\nHEIGHT : %d\n\n", env->width, env->height);
	printf("margin x : %d, margin y : %d\n", env->margin_x, env->margin_y);
	new_origin = (env->width * env->margin_y) + env->margin_x;
	printf("new_origin : %d", new_origin);
	y = 0;
	while (y < env->y_len)
	{
		x = 0;
		while (x < env->x_len)
		{
			z = env->matrix[y][x];
			z_next = env->matrix[y][x + 1];
			if (x + 1 < env->x_len && z == z_next)
			{
				k = 0;
				while (k < env->scale)
				{
					env->data_addr[new_origin + (x * env->scale) + ((y * env->scale) * env->width) + k] = mlx_get_color_value(env->mlx, 0x00FFFFFF);
					//printf("%5d", new_origin + (x * env->scale) + ((y * env->scale) * env->width) + k);
					k++;
				}
			}
			else if (z_next > z)
				diago_montant(env, x, y, new_origin);
			else if (z_next < z)
			{
				diago_descendant(env, x, y, new_origin);
			}
			z_next = env->matrix[y + 1][x];
			if (y + 1 < env->y_len && z == z_next)
			{
				k = 1;
				while (k <= env->scale)
				{
					env->data_addr[new_origin + (x * env->scale) + ((y * env->scale) * env->width) + (k * env->width)] = mlx_get_color_value(env->mlx, 0x00FFFFFF);
					//printf("%3d\n",new_origin + (x * env->scale) + ((y * env->scale) * env->width) + (k * env->width));
					k++;
				}
			}
			else if (z_next < z)
			{
				diago_montant(env, x, y, new_origin);
			}
			else if (z_next > z)
			{
				diago_descendant(env, x, y, new_origin);
			}
			x++;
		}
		printf("\n");
		y++;
	}	
}

t_points		*ft_calculate_x_prime(t_points *point, t_env *env, int index)
{
	//int		x_prime;
	double		cosinus;
	double		sinus;
	t_points	tmp;

	if (index == 0)
	{
		cosinus = cos(env->rotation_x);
		sinus = sin(env->rotation_x);
		tmp.x = point->z * sinus + point->x * cosinus;
		tmp.y = point->y;
		tmp.z = point->z * cosinus - point->x * sinus;
		return (ft_calculate_x_prime(&tmp, env, index + 1));
	}
	else if (index == 1)
	{
		cosinus = cos(env->rotation_y);
		sinus = sin(env->rotation_y);
		tmp.x = point->x;
		tmp.y = point->y * cosinus - point->z * sinus;
		tmp.z = point->y * sinus + point->z * cosinus;
		return (ft_calculate_x_prime(&tmp, env, index + 1));
	}
	else if (index == 2)
	{	
		cosinus = cos(env->rotation_z);
		sinus = sin(env->rotation_z);
		tmp.x = point->x * cosinus - point->y * sinus;
		tmp.y = point->x * sinus + point->y * cosinus;
		tmp.z = point->z;
		return (ft_calculate_x_prime(&tmp, env, index + 1));
	}
	return (point);
}

double			ft_rotate(t_points *point, t_env *env)
{
	double		coords;
	double		x_prime;
	double		y_prime;
	int			index;
	int			new_origin;

	new_origin = (env->width * env->margin_y) + env->margin_x;
	index = 0;
	point = ft_calculate_x_prime(point, env, index);
	x_prime = point->x * env->fov / (point->z + env->view_distance) / (env->width / 2);
	y_prime = (0 - point->y) * env->fov / (point->z + env->view_distance) / (env->height / 2);
	coords = new_origin + (x_prime * env->scale) + ((y_prime * env->scale) * env->width);
	return (coords);
}

void		draw_line_left(int old, int new, t_env *env)
{
	int		x_new;
	int		y_new;
	int		x_old;
	int		y_old;
	int		x;
	int		x_c;
	int		y_c;
	int		new_coord;

	x_new = new % env->width;
	x_old = old % env->width;
	y_new = new / env->height;
	y_old = old / env->height;
	
	if (x_old < x_new)
	{
		x = x_old;
		while (x < x_new)
		{
			x_c = x;
			y_c = y_old + ((y_new - y_old) * (x - x_old)) / (x_new - x_old);
			new_coord = y_c * env->height + x_c;
			env->data_addr[new_coord] = mlx_get_color_value(env->mlx, 0x00FFFFFF);
			x++;
		}
	}
	printf("old num : %d, new num : %d\n", old, new);
	printf("old coord : (%d, %d) new coord : (%d, %d)\n", x_old, y_old, x_new, y_new);
}


void		ft_draw_points(t_env *env)
{
	double			x;
	double			y;
	double			x_prime;
	double			y_prime;
	int			new_origin;
	int			new_point;
	t_points	point;
	int			count;
	int			i;
	int			old_point;
	int			low_point;
	t_points	low;
	t_points	high;

	count = 0;
	old_point = 0;
	new_origin = (env->width * env->margin_y) + env->margin_x;
	y = 0;
	printf("height : %d width : %d\n", env->height, env->width);
	printf("x len  : %d y len : %d\n", env->x_len, env->y_len);
	while (y < env->y_len)
	{
		//printf("\n");
		x = 0;
		while (x < env->x_len)
		{
			count++;
			x_prime = (1 * x) - (1 * y);
			y_prime = (0 - (env->matrix[(int)y][(int)x] / 3)) + (0.5 * x) + (0.5 * y);
		//	i = 1;
		//	while (i < env->scale)
		//	{	
			new_point = (double)new_origin + (x_prime  * (double)env->scale) +
				((y_prime *  (double)env->scale) * env->width);
		//	printf("%u\n", env->data_addr[new_point]);
			env->data_addr[new_point] = mlx_get_color_value(env->mlx, 0x00FFFFFF);
			/*if (env->matrix[(int)y][(int)x] > 0)
			{
				x_prime = (1 * x) - (1 * y);
				y_prime = (0 - (0 / 5)) + (0.5 * x) + (0.5 * y);
				low_point =  new_origin + (x_prime  *(double)env->scale) + ((y_prime *  (double)env->scale) * env->width);
				low.x = low_point % env->width;
				low.y = low_point / env->height;
				high.x = new_point % env->width;
				high.y = new_point / env->width;
				i = high.y;
				printf("high y : %d, low y : %d\n", high.y, low.y);
				while (i < low.y)
				{
					printf("i : %d\n", i);
					env->data_addr[low.x + (i * env->height)] = mlx_get_color_value(env->mlx, 0x00FF0000);
					i++;
				}
			}*/
			if (old_point && ((int)x % env->width - 1) != 0)
				;
				//draw_line_left(old_point, new_point, env);
		//	old_point = new_point;
			x++;
			//printf("x : %f\n", x);
		}
		y++;
		//printf("y : %f\n", y);
	}
	printf("count: %d\n", count);
}

int			ft_calculate_position(int x, int y, t_env *env)
{
	double	x_prime;
	double	y_prime;
	int		position;
	int		new_origin;

	x_prime = (1 * x) - (1 * y);
	y_prime = (0 - (env->matrix[(int)y][(int)x] / 3)) + (0.5 * x) + (0.5 * y);
	position = (double)env->new_origin + (x_prime * (double)env->scale) + ((y_prime * (double)env->scale) * env->width);
	return (position);
}

void		ft_draw_vertical_line(int a, int b, t_env *env)
{
	int		position;

	position = a;
	while (position < b)
	{
		env->data_addr[position] = mlx_get_color_value(env->mlx, 0x00FFFFFF);
		position = position + env->width;
	}
}

void		ft_draw_atob_lines(t_env *env)
{
	int		y;
	int		x;
	int		a;
	int		b;

	y = 0;
	while (y < env->y_len)
	{
		x = 0;
		while (x < env->x_len)
		{
			a = ft_calculate_position(x, y, env);
			b = ft_calculate_position(x + 1, y, env);
			if (env->matrix[y][x] > 0 && env->matrix[y][x + 1] == 0)
				ft_draw_vertical_line(a, b, env);
			x++;
		}
		y++;
	}
}
int			ft_create_image(t_env *env)
{
	unsigned int		color;

	env->win = mlx_new_window(env->mlx, (env->width), (env->height), env->title);
	env->img = mlx_new_image(env->mlx, (env->width), (env->height));
	env->data_addr = (unsigned int*)mlx_get_data_addr \
					 (env->img, &env->bits_per_pixel, &env->bytes_per_line, &env->endian);
	color = mlx_get_color_value(env->mlx, 0x00FFFFFF);
	//ft_display_coords(env);
	ft_draw_points(env);
	ft_draw_atob_lines(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
