/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:46:55 by pfaust            #+#    #+#             */
/*   Updated: 2018/01/09 16:58:41 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static t_points		*ft_newpoint(int x, int y, int z)
  {
  t_points		*new;

  if (!(new = (t_points*)malloc(sizeof(t_points))))
  return (NULL);
  new->x = x;
  new->y = y;
  new->z = z;
  new->next = NULL;
  return (new);
  }*/

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
		{
			atoi_line[i] = ft_atoi(tab[i]);
			//printf("str avant : %10s nbr : %5d i : %5d \n", tab[i], atoi_line[i], i);
		}
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
		j = 0;
	//	while (j++ < env->x_len)
	//		ft_putnbr((*env->matrix)[j]);
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
	//ft_open_window(argv);
	return (0);
}
