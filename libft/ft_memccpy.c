/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:06:34 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/17 15:11:26 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dest;
	unsigned char			*cpy;
	unsigned int			i;

	dest = (unsigned char*)dst;
	cpy = (unsigned char*)src;
	i = 0;
	while (n--)
	{
		if (cpy[i] == (unsigned char)c)
		{
			dest[i] = cpy[i];
			return (&dest[i + 1]);
		}
		dest[i] = cpy[i];
		i++;
	}
	return (NULL);
}
