/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:14:56 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/23 12:15:47 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbwords(const char *s, char c)
{
	unsigned int	i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
			i++;
		else
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (nb);
}
