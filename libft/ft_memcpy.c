/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:53:34 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/14 17:04:23 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dest;
	char			*cpy;
	unsigned int	i;

	dest = (char*)dst;
	cpy = (char*)src;
	i = 0;
	while (n--)
	{
		dest[i] = cpy[i];
		i++;
	}
	return (dest);
}
