/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:39:41 by enunes            #+#    #+#             */
/*   Updated: 2017/09/14 21:55:35 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_check(char **rest, char **line)
{
	char			*tmp;

	tmp = ft_strchr(*rest, '\n');
	if (!tmp)
		return (0);
	*line = ft_strsub(*rest, 0, tmp - *rest);
	ft_memmove(*rest, tmp + 1, ft_strlen(tmp));
	tmp = NULL;
	return (1);
}

static	int			ft_read(int fd, char **rest, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	char			*temp;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		temp = NULL;
		if (*rest)
		{
			temp = ft_strdup(*rest);
			ft_memdel((void **)rest);
			*rest = ft_strjoin(temp, buff);
			ft_memdel((void **)&temp);
		}
		else
			*rest = ft_strdup(buff);
		if (ft_check(rest, line))
			return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static	char	*rest[100 + 1];
	int				result;

	if (!line || fd < 0 || fd > 100)
		return (-1);
	if (rest[fd] && ft_check(&rest[fd], line))
		return (1);
	result = ft_read(fd, &rest[fd], line);
	if (result != 0)
		return (result);
	if (rest[fd] == NULL || rest[fd][0] == '\0')
		return (0);
	*line = rest[fd];
	rest[fd] = NULL;
	return (1);
}
