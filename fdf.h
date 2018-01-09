/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:59:18 by pfaust            #+#    #+#             */
/*   Updated: 2018/01/09 16:36:29 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
#include <mlx.h>
//A RETIRER
#include <stdio.h>

typedef struct		s_points
{
	int				x;
	int				y;
	int				z;
	struct s_points	*next;
}					t_points;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				fd;
	int				**matrix;
	int				y_len;
	int				x_len;
}					t_env;

void				ft_open_window(char **argv);
#endif
