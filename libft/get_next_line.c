/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:23:24 by pfaust            #+#    #+#             */
/*   Updated: 2018/01/04 12:09:07 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_stock	*ft_newstock(int fd)
{
	t_stock	*new;

	if (!(new = (t_stock*)malloc(sizeof(t_stock))))
		return (NULL);
	new->fd = fd;
	new->str = ft_strnew(0);
	new->done = 0;
	new->next = NULL;
	return (new);
}

static char		*ft_read_file_extra(char *buf, char *eol, char **line,
		t_stock **elem)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strsub(buf, 0, (eol - buf));
	tmp2 = ft_strjoin((*elem)->str, tmp);
	*line = ft_strdup(tmp2);
	ft_strdel(&(*elem)->str);
	ft_strdel(&tmp);
	(*elem)->str = ft_strsub(buf, (eol - buf + 1), (ft_strlen(eol) - 1));
	ft_strdel(&tmp2);
	return (*line);
}

static int		free_and_empty(char **line, t_stock *elem)
{
	*line = ft_strdup(elem->str);
	free(elem->str);
	if (!(elem->str = ft_strnew(0)))
		return (-1);
	return (1);
}

static int		ft_read_file(const int fd, char **line, t_stock *elem)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*eol;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((eol = ft_strchr(buf, '\n')))
		{
			*line = ft_read_file_extra(buf, eol, line, &elem);
			return (1);
		}
		else
		{
			tmp = elem->str;
			elem->str = ft_strjoin(elem->str, buf);
			ft_strdel(&tmp);
		}
	}
	if (ret == -1)
		return (-1);
	if (ft_strlen(elem->str) > 0 && !(eol = ft_strchr(elem->str, '\n')))
		return (free_and_empty(line, elem));
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_stock		*list;
	t_stock				*elem;
	char				*eol;
	char				*tmp;

	if (!list && !(list = ft_newstock(fd)))
		return (-1);
	elem = list;
	while (elem->fd != fd && elem->next)
		elem = elem->next;
	if (!elem->next && elem->fd != fd)
	{
		elem->next = ft_newstock(fd);
		elem = elem->next;
	}
	if ((eol = ft_strchr(elem->str, '\n')))
	{
		*line = ft_strsub(elem->str, 0, (eol - elem->str));
		tmp = elem->str;
		elem->str = ft_strsub(tmp, (eol - tmp + 1), ft_strlen(eol));
		ft_strdel(&tmp);
		return (1);
	}
	return (ft_read_file(fd, line, elem));
}
