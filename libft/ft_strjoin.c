/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:52:02 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/16 19:02:52 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*cpy;

	cpy = NULL;
	if (s1 && s2)
	{
		cpy = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (cpy == 0)
			return (NULL);
		ft_strcpy(cpy, s1);
		ft_strcat(cpy, s2);
	}
	return (cpy);
}
