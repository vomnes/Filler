/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:25:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/25 09:01:25 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
# define ENDOFL	'\n'

int		ft_strjoinbis(char **line, char *buf)
{
	char	*tmp;

	if ((tmp = ft_strjoin(*line, buf)) == NULL)
		return (-1);
	free(*line);
	*line = tmp;
	return (1);
}

int		ft_init(char **buf, int fd, char **line)
{
	int ret;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || ENDOFL == '\0')
		return (-1);
	else
	{
		if ((*line = (char*)malloc(sizeof(char) * 1)) == NULL)
			return (-1);
	}
	**line = '\0';
	if (*buf == NULL)
	{
		if ((*buf = (char*)ft_memalloc(BUFF_SIZE + 1)) == NULL)
			return (-1);
		if ((ret = read(fd, *buf, BUFF_SIZE)) == -1)
			return (-1);
		else
			return (ret);
	}
	return (1);
}

int		ft_clean(char ***line, char **buf)
{
	if (ft_strlen(**line))
		return (1);
	else
	{
		ft_strdel(*line);
		ft_strdel(buf);
		return (0);
	}
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf = NULL;
	int			ret;

	if (((ret = ft_init(&buf, fd, line)) == -1))
		return (-1);
	while (ft_strchr(buf, ENDOFL) == NULL && ret != 0)
	{
		if (ft_strjoinbis(line, buf) == -1)
			return (-1);
		ft_memset(buf, '\0', BUFF_SIZE + 1);
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
	}
	if (ft_strchr(buf, ENDOFL))
	{
		*(ft_strchr(buf, ENDOFL)) = '\0';
		if (ft_strjoinbis(line, buf) == -1)
			return (-1);
		ft_memmove(buf, ft_strchr(buf, 0) + 1, BUFF_SIZE - ft_strlen(buf));
		return (1);
	}
	return (ft_clean(&line, &buf));
}
