/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:40:54 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 14:38:17 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char			*map;
	char			*str;
	unsigned int	i;

	map = NULL;
	if (s)
	{
		str = (char*)s;
		if (((map = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))) == 0))
			return (NULL);
		i = 0;
		while (str[i])
		{
			map[i] = f(str[i]);
			i++;
		}
		map[i] = '\0';
	}
	return (map);
}
