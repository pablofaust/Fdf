/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:08:42 by pfaust            #+#    #+#             */
/*   Updated: 2018/01/05 15:47:08 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(void *mlx, void *win)
{
	mlx_pixel_put(mlx, win, 500, 500, 0x00FFFFFF); 
}

int		expose_hook(t_env *env)
{
	ft_draw(env->mlx, env->win);
	return (0);
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	return (0);
}
void	ft_open_window(char **argv)
{
	t_env		env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1000, 1000, argv[1]);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
}
