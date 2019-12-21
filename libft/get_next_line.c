/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 17:31:56 by gaudry            #+#    #+#             */
/*   Updated: 2019/12/16 19:19:48 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*get_new(char **buf1)
{
	int				i;
	char			*new;
	char			*tmp;

	i = 0;
	tmp = *buf1;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			break ;
		i++;
	}
	if (tmp[i] != '\n')
	{
		new = ft_strsub(*buf1, 0, ft_strlen(tmp));
		*buf1 = ft_strsub(*buf1, i, 0);
	}
	else
	{
		new = ft_strsub(*buf1, 0, i);
		*buf1 = ft_strsub(*buf1, i + 1, ft_strlen(*buf1) - i);
	}
	ft_strdel(&tmp);
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	size_t			i;
	static char		*str[4096];
	char			*delstr;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0
		|| (!str[fd] && !(str[fd] = ft_strnew(1))))
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while (!(ft_strchr(str[fd], '\n')) && (i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		delstr = str[fd];
		str[fd] = ft_strjoin(str[fd], buf);
		ft_strdel(&delstr);
	}
	if (i == 0 && !*str[fd])
		return (0);
	*line = get_new(&str[fd]);
	if ((*line && (*str[fd] == '\0' || **line == '\0')))
		return (1);
	return ((**line) ? 1 : 0);
}
