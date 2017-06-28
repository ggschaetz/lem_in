/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:29:21 by gschaetz          #+#    #+#             */
/*   Updated: 2017/01/24 11:27:47 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_line(char **line, char *rest)
{
	int i;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	*line = ft_strsub(rest, 0, i);
	return (*line);
}

char		*ft_rest(char *rest)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = ft_memalloc(ft_strlen(rest));
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	if (rest[i] == '\0')
		tmp[0] = '\0';
	else
	{
		i++;
		while (rest[i] != '\0')
			tmp[j++] = rest[i++];
	}
	free(rest);
	return (tmp);
}

char		*ft_strjoinfree(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*d;

	i = 0;
	j = 0;
	if (!(s1) || !(s2))
		return (NULL);
	if (!(d = (char *)malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
		d[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		d[j++] = s2[i++];
	d[j] = '\0';
	free((void *)s1);
	return (d);
}

int			ft_bullshit(char *rest, char **line, int ret)
{
	if (rest[0] == '\0' && *line[0] == '\0' && ret == 0)
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*rest;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	ret = 1;
	if (rest == NULL)
		rest = ft_memalloc(0);
	if (fd < 0 || !(line))
		return (-1);
	while (ft_strchr(rest, '\n') == NULL && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		else
		{
			buf[ret] = '\0';
			rest = ft_strjoinfree(rest, buf);
		}
	}
	*line = ft_line(line, rest);
	tmp = ft_strdup(rest);
	free(rest);
	rest = ft_rest(tmp);
	return (ft_bullshit(rest, line, ret));
}
