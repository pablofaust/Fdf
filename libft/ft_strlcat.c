/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:50:39 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 14:53:55 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	char			*dst;
	char			*cat;
	int				len;
	int				size;

	dst = dest;
	cat = (char*)src;
	size = (int)n;
	while (size-- != 0 && *dst != 0)
		dst++;
	len = dst - dest;
	size = (int)n - len;
	if (size == 0)
		return (len + ft_strlen(cat));
	while (*cat)
	{
		if (size != 1)
		{
			*dst++ = *cat;
			size--;
		}
		cat++;
	}
	*dst = 0;
	return (len + (cat - src));
}
