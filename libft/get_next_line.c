/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:35:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/15 17:57:22 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						clear_cursor(char **line, char **cursor,
															unsigned int *index)
{
	int i;

	i = 0;
	while ((*cursor)[*index] != 10 && (*cursor)[*index])
		(*line)[i++] = (*cursor)[(*index)++];
	(*line)[i] = 0;
	return (i);
}

char					*strndup_end(char s1[SIZE + 1], size_t size)
{
	char				*s2;
	size_t				i;

	i = 0;
	if (ft_strlen(s1) <= size || !s1)
		return (NULL);
	if (!(s2 = ft_strnew(sizeof(char) * ((ft_strlen(s1) - size) + 1))))
		return (NULL);
	while (s1[size])
		s2[i++] = s1[size++];
	s2[i] = 0;
	return (s2);
}

int						other(char **line, char **cursor, int i)
{
	if (i > 0)
		*line = ft_realloc((void*)*line, ft_strlen(*line) + SIZE);
	ft_strdel(cursor);
	return (0);
}

int						ft_getline(int fd, char **line, char **cursor,
															unsigned int *index)
{
	int					i[3];
	char				buff[SIZE + 1];

	i[RETURN] = 1;
	i[LINE] = (*cursor) ? clear_cursor(line, cursor, index) : 0;
	if (!(*cursor) || !(*cursor)[*index])
	{
		*index = other(line, cursor, i[LINE]);
		while ((i[RETURN] = read(fd, buff, SIZE)) > 0)
		{
			i[BUFF] = 0;
			buff[i[RETURN]] = 0;
			while (buff[i[BUFF]] && buff[i[BUFF]] != 10)
				(*line)[i[LINE]++] = buff[i[BUFF]++];
			if (buff[i[BUFF]] == 10)
			{
				*cursor = strndup_end(buff, (i[BUFF] + 1));
				break ;
			}
			else
				*line = ft_realloc((void*)*line, ft_strlen(*line) + SIZE);
		}
	}
	(*cursor && (*cursor)[*index] == 10) ? (*index)++ : *index;
	return ((ft_strlen(*line)) ? 1 : i[RETURN]);
}

int						get_next_line(int const fd, char **line)
{
	int					ret;
	static char			*cursor;
	static unsigned int	index;

	if (!line || fd < 0 || SIZE <= 0)
		return (-1);
	if (!(*line = ft_strnew(sizeof(char) * (SIZE + 1))))
		return (-1);
	ret = ft_getline(fd, line, &cursor, &index);
	if (!ft_strlen(*line))
		ft_strdel(line);
	return (ret);
}
