/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:29:33 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/21 11:48:13 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_issep(char c)
{
	if (c == ' ' || c == '0' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int				neg;
	int				nb;
	int				i;

	neg = 1;
	nb = 0;
	i = 0;
	while (ft_issep((unsigned char)str[i]) == 1)
		i++;
	if ((unsigned char)str[i] == '+')
		i++;
	if ((unsigned char)str[i] == '-' && (unsigned char)str[i - 1] != '+')
	{
		neg = -1;
		i++;
	}
	while ((unsigned char)str[i])
	{
		if ((unsigned char)str[i] >= '0' && (unsigned char)str[i] <= '9')
			nb = (nb * 10) + neg * ((unsigned char)str[i] - 48);
		else
			return (nb);
		i++;
	}
	return (nb);
}
