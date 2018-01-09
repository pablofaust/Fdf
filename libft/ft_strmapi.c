/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:51:17 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 14:37:34 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*map;
	unsigned int	i;

	map = NULL;
	if (s)
	{
		str = (char*)s;
		if (((map = (char*)malloc(sizeof(char) * (ft_strlen(str)) + 1)) == 0))
			return (NULL);
		i = 0;
		while (str[i])
		{
			map[i] = f(i, str[i]);
			i++;
		}
		map[i] = '\0';
	}
	return (map);
}
