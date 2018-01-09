/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:25:07 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/23 12:15:54 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(const char *s, char c)
{
	char			**splits;
	unsigned int	i;
	unsigned int	len;
	int				word;

	word = 0;
	if (!(s))
		return (NULL);
	if (!(splits = (char**)malloc(sizeof(char*) * (ft_nbwords(s, c) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
			i++;
		else
		{
			len = ft_wordlen(s, i, c);
			if (!(splits[word++] = ft_strsub(s, i, len)))
				return (NULL);
			i = i + len;
		}
	}
	splits[word] = 0;
	return (splits);
}
