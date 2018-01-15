/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_to_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:52:45 by pfaust            #+#    #+#             */
/*   Updated: 2018/01/11 14:34:47 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_points		*ft_newpoint(int x, int y, int z)
{
	t_points		*new;

	if (!(new = (t_points*)malloc(sizeof(t_points))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	return (new);
}

t_points			*ft_stock_to_struct(t_env *env)
{
	t_points	*points;
	t_points	*point;
	t_points	*tmp;
	int			x;
	int			y;
	
	y = 0;
	while (y < env->y_len)
	{
		x = 0;
		while (x < env->x_len)
		{
			if (!points)
				points = ft_newpoint(x + 99, y + 99, env->matrix[y][x]);
			else
			{
				ft_putendl("ok");
				tmp = points;
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = ft_newpoint(x + 99, y + 99, env->matrix[y][x]);
			}
			x++;
		}
		printf("\n");
		y++;
	}
	while (points->next)
	{
		ft_putendl("ok");
		dprintf(1, "x : %d, y : %d, z : %d\n", points->x, points->y, points->z);
		points = points->next;
	}
	return (points);
}
