/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:08:08 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/23 11:29:28 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2) && n != 0)
		return (0);
	while (s1[i] && s2[i] && n--)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
