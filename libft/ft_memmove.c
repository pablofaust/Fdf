/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:43:18 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 12:22:32 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;

	dest = dst;
	if (len)
	{
		if (dest < (unsigned char*)src)
			while (len--)
				*(unsigned char*)dest++ = *(unsigned char*)src++;
		else
			while (len--)
				((unsigned char*)dest)[len] = ((unsigned char*)src)[len];
	}
	return (dst);
}
