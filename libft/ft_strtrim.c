/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:09:44 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 14:35:00 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static size_t		ft_trimlen(const char *str)
{
	size_t			len;
	unsigned int	i;

	i = 0;
	while ((ft_isspace(str[i]) == 1) && str[i])
		i++;
	len = 0;
	while (str[i])
	{
		i++;
		len++;
	}
	while ((i > 0) && (len > 0) && (ft_isspace(str[i - 1]) == 1))
	{
		i--;
		len--;
	}
	return (len);
}

char				*ft_strtrim(const char *s)
{
	char			*str;
	unsigned int	i;

	str = NULL;
	if (s)
	{
		i = 0;
		while (ft_isspace(s[i]) == 1)
			i++;
		if (!(str = ft_strsub(s, i, ft_trimlen(s))))
			return (NULL);
		return (str);
	}
	return (str);
}
