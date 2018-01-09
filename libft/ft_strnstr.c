/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:18:15 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/17 16:02:38 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule, const char *aiguille, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (*aiguille == '\0')
		return ((char*)meule);
	i = 0;
	j = 0;
	while (meule[i] && i < n)
	{
		while ((meule[j + i] == aiguille[j]) && (i + j < n))
		{
			j++;
			if (aiguille[j] == '\0')
				return ((char*)&meule[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
