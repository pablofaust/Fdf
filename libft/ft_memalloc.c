/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:17:29 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 14:39:01 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*mem;

	if (((mem = (void*)malloc(sizeof(size_t) * (size) + 1)) == 0))
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
