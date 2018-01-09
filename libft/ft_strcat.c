/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:46:50 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/15 16:11:08 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	unsigned long	i;
	size_t			len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[(len + i)] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
