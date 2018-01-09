/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:33:54 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 14:24:37 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_intlen_fd(unsigned int n)
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

unsigned int		ft_pw_fd(unsigned int len)
{
	unsigned int		pow;

	pow = 1;
	while (--len > 0)
		pow = 10 * pow;
	return (pow);
}

void				ft_putnbr_fd(int c, int fd)
{
	unsigned int	i;
	unsigned int	pow;
	unsigned int	len;

	i = 0;
	if (c < 0)
	{
		ft_putchar_fd('-', fd);
		c = (unsigned int)-c;
	}
	len = ft_intlen_fd(c);
	if (c == 0)
		ft_putchar_fd('0', fd);
	while (len)
	{
		pow = ft_pw_fd(len--);
		ft_putchar_fd(((c / pow) + 48), fd);
		c = c % pow;
	}
}
