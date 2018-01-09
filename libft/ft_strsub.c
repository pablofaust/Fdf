/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:42:12 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/17 18:02:52 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*str;
	char			*sub;
	unsigned int	i;

	sub = NULL;
	if (s)
	{
		str = (char*)s;
		if (((sub = (char*)malloc(sizeof(char) * (len) + 1)) == 0))
			return (NULL);
		i = 0;
		while (str[i + start] && len--)
		{
			sub[i] = str[i + start];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}
