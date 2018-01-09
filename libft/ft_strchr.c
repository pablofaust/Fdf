/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:42:21 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 14:46:51 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;
	char			*str;
	char			*ptr;

	str = (char*)s;
	i = 0;
	ptr = str;
	if ((char)c == '\0')
	{
		while (*str)
			str++;
		return (str);
	}
	while (str[i])
	{
		if (str[i] == (char)c)
			return (ptr);
		else
		{
			i++;
			ptr++;
		}
	}
	return (0);
}
