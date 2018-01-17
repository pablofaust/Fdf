/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_CREATE_IMAGE.C                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   BY: PFAUST <MARVIN@42.FR>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   CREATED: 2018/01/10 14:44:01 BY PFAUST            #+#    #+#             */
/*   Updated: 2018/01/17 18:19:47 by pfaust           ###   ########.fr       */
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

void		ft_display_coords(t_env *env)
{
	int		x;
	int		y;
	int		k;
	int		m;
	int		x_prime;
	int		y_prime;
	int		**modified_matrix;
	int		new_origin;
	unsigned int color[100] = {0x00808080,0x00FFFFFF}; 

	printf("WIDTH : %d\n\nHEIGHT : %d\n\n", env->width, env->height);
	printf("margin x : %d, margin y : %d\n", env->margin_x, env->margin_y);
	new_origin = (env->width * env->margin_y) + env->margin_x;
	y = 0;
	while (y < env->y_len)
	{
		x = 0;
		while (x < env->x_len)
		{
			if (x + 1 < env->x_len && env->matrix[y][x] == env->matrix[y][x + 1])
			{
				k = 0;
				while (k < env->scale)
				{
					env->data_addr[new_origin + (x * env->scale) + ((y * env->scale) * env->width) + k] = mlx_get_color_value(env->mlx, 0x00FFFFFF);
					printf("%5d", new_origin + (x * env->scale) + ((y * env->scale) * env->width) + k);
					k++;
				}
			}
			printf("\n");
			if (y + 1 < env->y_len && env->matrix[y][x] == env->matrix[y + 1][x])
			{
				k = 1;
				while (k <= env->scale)
				{
					env->data_addr[new_origin + (x * env->scale) + ((y * env->scale) * env->width) + (k * env->width)] = mlx_get_color_value(env->mlx, 0x00FFFFFF);
					printf("%3d\n",new_origin + (x * env->scale) + ((y * env->scale) * env->width) + (k * env->width));
					k++;
				}
			}
			x++;
		}
		printf("\n");
		y++;
	}	
}

void		ft_display_coords_modif(t_env *env)
{
	int		i;
	int		j;
	int		k;
	int		m;
	int		x_prime;
	int		y_prime;
	int		**modified_matrix;

	j = 0;
	while (j < env->y_len)
	{
		i = 0;
		while (i < env->x_len)
		{
			//x_prime = i * 3 / (env->matrix[j][i] + 1) + ((env->x_len * 10) / 2);
			//y_prime = -j * 3 / (env->matrix[j][i] + 1) + ((env->y_len * 10) / 2);
			ft_putnbr(-j);
			dprintf(1, "x : %d, y : %d, z : %d\nx' : %d, y' : %d\n\n", i, j, env->matrix[j][i], x_prime, y_prime);
			k = 1;
			while (k <= 10)
			{
				m = 1;
				while (m <= 10)
				{
					env->data_addr[(y_prime * env->y_len * k) + (y_prime * m)] = mlx_get_color_value(env->mlx, 0x00FFFFFF);
					m++;
				}
				k++;
			}
			i++;
		}
		printf("\n");
		j++;
	}	
}

int			ft_create_image(t_env *env)
{
	unsigned int		color;

	env->img = mlx_new_image(env->mlx, (env->width), (env->height));
	env->win = mlx_new_window(env->mlx, (env->width), (env->height), env->title);
	env->data_addr = (unsigned int*)mlx_get_data_addr \
					 (env->img, &env->bits_per_pixel, &env->bytes_per_line, &env->endian);
	color = mlx_get_color_value(env->mlx, 0x00FFFFFF);
	ft_display_coords(env);
	//ft_fill_window(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
