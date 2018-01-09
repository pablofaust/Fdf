/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:32:32 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 14:54:22 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*cmp;

	str = (unsigned char*)s1;
	cmp = (unsigned char*)s2;
	if (n)
	{
		i = 0;
		if (str[i] == '\0' && cmp[i])
			return (0 - cmp[i]);
		if (cmp[i] == '\0' && str[i])
			return (str[i]);
		while (n--)
		{
			if (str[i] == cmp[i])
				i++;
			else
				return (str[i] - cmp[i]);
		}
	}
	return (0);
}
