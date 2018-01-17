/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:46:55 by pfaust            #+#    #+#             */
/*   Updated: 2018/01/17 18:20:07 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					*ft_atoi_tab_to_line(char **tab, t_env *env)
{
	int		i;
	int		*atoi_line;

	atoi_line = NULL;
	if (tab)
	{
		if (!(atoi_line = malloc(sizeof(int) * env->x_len)))
			return (NULL);
		i = -1;
		while (tab[++i])
			atoi_line[i] = ft_atoi(tab[i]);
	}
	else
		return (NULL);
	return (atoi_line);
}

t_env				*ft_add_to_matrix(t_env *env, int *tab)
{
	int		**tmp;
	int		i;
	int		j;
	

	if (!(tmp = malloc(sizeof(int*) * env->y_len)))
		return (NULL);
	i = 0;
	while (i < env->y_len - 1 && env->matrix)
	{
		tmp[i] = env->matrix[i];
		i++;
	}
	tmp[i] = tab;
	free(env->matrix);
	env->matrix = tmp;
	return (env);
}

int					**ft_stock_map_in_tab(t_env *env)
{
	char	*line;
	char	**splits;
	int		*tab;
	int		i;
	int		j;

	while (get_next_line(env->fd, &line))
	{
		env->x_len = ft_nbwords(line, ' ');
		env->y_len = env->y_len + 1;
		splits = ft_strsplit(line, ' ');
		tab = ft_atoi_tab_to_line(splits, env);
		env = ft_add_to_matrix(env, tab);
	}
	j = 0;
	while (j < env->y_len)
	{
		i = 0;
		while (i < env->x_len)
		{
			printf("%5d",env->matrix[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	return (NULL);
}

int					main (int argc, char **argv)
{
	t_env		env;
	int			**tab;

	if (argc < 2 || argc > 2)
	{
		ft_putendl("Usage : ./fdf [inputfile]");
		return (0);
	}
	env.fd = open(argv[1], O_RDONLY);
	env.matrix = NULL;
	env.y_len = 0;
	tab = ft_stock_map_in_tab(&env);
	env.mlx = mlx_init();
	env.title = argv[1];
	env.scale = 10;
	env.width = (env.x_len - 1) * env.scale * 2;
	env.height = (env.y_len - 1) * env.scale * 2;
	env.margin_x = (env.width / 2) / 2;
	env.margin_y = (env.height /2) / 2;
	ft_create_image(&env);
	return (0);
}
