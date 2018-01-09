/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:27:41 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/15 15:57:28 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strnew(size_t size)
{
	char			*mem;

	if (((mem = (char*)malloc(sizeof(*mem) * (size + 1))) == 0))
		return (NULL);
	ft_memset(mem, '\0', (size + 1));
	return ((void*)mem);
}
