/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:26:16 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/23 12:04:25 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_itoalen(unsigned int n)
{
	size_t		len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char					*ft_itoa(int n)
{
	char			*itoa;
	size_t			len;
	unsigned int	i;
	unsigned int	pow;

	itoa = NULL;
	if (!(itoa = (char*)malloc(sizeof(char) * (ft_itoalen(n) + 1))))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		itoa[i++] = '-';
		n = (unsigned int)-n;
	}
	len = ft_itoalen(n);
	if (n == 0)
		itoa[i++] = '0';
	while (len)
	{
		pow = ft_pow(len--);
		itoa[i++] = (n / pow) + '0';
		n = n % pow;
	}
	itoa[i] = '\0';
	return (itoa);
}
