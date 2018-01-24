/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:59:18 by pfaust            #+#    #+#             */
/*   Updated: 2018/01/24 15:39:42 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
#include <mlx.h>
#include <math.h>
//A RETIRER
#include <stdio.h>

typedef struct		s_points
{
	int			x;
	int			y;
	int			z;
}					t_points;

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*title;
	unsigned int			*data_addr;
	int						bits_per_pixel;
	int						bytes_per_line;
	int						endian;
	int						fd;
	int						**matrix;
	int						y_len;
	int						x_len;
	int						width;
	int						height;
	int						margin_x;
	int						margin_y;
	int						scale;
	int						fov;
	int						view_distance;
	double					rotation_x;
	double					rotation_y;
	double					rotation_z;
}							t_env;

void				ft_open_window(char **argv);
int					ft_create_image(t_env *env);
t_points			*ft_stock_to_struct(t_env *env);
#endif
