/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:18:34 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 14:25:49 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_intlen(unsigned int n)
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

static unsigned int		ft_pw(unsigned int len)
{
	unsigned int		pow;

	pow = 1;
	while (--len > 0)
		pow = 10 * pow;
	return (pow);
}

void					ft_putnbr(int c)
{
	unsigned int	i;
	unsigned int	pow;
	unsigned int	len;

	i = 0;
	if (c < 0)
	{
		ft_putchar('-');
		c = (unsigned int)-c;
	}
	len = ft_intlen(c);
	if (c == 0)
		ft_putchar('0');
	while (len)
	{
		pow = ft_pw(len--);
		ft_putchar((c / pow) + 48);
		c = c % pow;
	}
}
