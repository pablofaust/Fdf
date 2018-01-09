/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:51:58 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/22 13:44:46 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*ptr;
	t_list	*new;

	map = NULL;
	if (lst && f)
	{
		while (lst)
		{
			new = (*f)(lst);
			if (map)
			{
				ptr->next = new;
				ptr = ptr->next;
			}
			else
			{
				map = new;
				ptr = map;
			}
			lst = lst->next;
		}
		return (map);
	}
	return (NULL);
}
