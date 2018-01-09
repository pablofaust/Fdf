/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:41:02 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/17 15:59:22 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule, const char *aiguille)
{
	unsigned int	i;
	unsigned int	j;

	if (*aiguille == '\0')
		return ((char*)meule);
	i = 0;
	j = 0;
	while (meule[i])
	{
		while (meule[j + i] == aiguille[j])
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
