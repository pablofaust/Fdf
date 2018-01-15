/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:44:01 by pfaust            #+#    #+#             */
/*   Updated: 2018/01/12 13:54:46 by pfaust           ###   ########.fr       */
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

int			ft_create_image(t_env *env)
{
	unsigned int		color;

	env->img = mlx_new_image(env->mlx, (env->x_len * 100), (env->y_len * 100));
	env->win = mlx_new_window(env->mlx, (env->x_len * 100 + 20), (env->y_len * 100 + 20), env->title);
	env->data_addr = (unsigned int*)mlx_get_data_addr \
	(env->img, &env->bits_per_pixel, &env->bytes_per_line, &env->endian);
	color = mlx_get_color_value(env->mlx, 0x00FFFFFF);
	env->data_addr[1] = color;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 10, 10);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
