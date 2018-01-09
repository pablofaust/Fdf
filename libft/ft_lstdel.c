/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:16:23 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/22 13:46:38 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*ptr;

	ptr = *alst;
	while (*alst)
	{
		*alst = ptr->next;
		del(ptr->content, ptr->content_size);
		free(ptr);
		ptr = *alst;
	}
	*alst = NULL;
}
