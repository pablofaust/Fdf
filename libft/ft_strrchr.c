/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:20:28 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/20 14:46:01 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	char			*ptr;
	unsigned int	count;

	str = (char*)s;
	count = 0;
	ptr = str;
	if ((char)c == '\0')
	{
		while (*str)
			str++;
		return (str);
	}
	while (*str)
	{
		if (*str == (char)c)
		{
			ptr = str;
			count++;
		}
		str++;
	}
	if (count > 0)
		return (ptr);
	return (0);
}
