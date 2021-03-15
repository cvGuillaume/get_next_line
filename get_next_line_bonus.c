/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:35:25 by gcornet-          #+#    #+#             */
/*   Updated: 2021/03/02 10:35:28 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strdup(const char *s1)
{
	char *s2;

	if (!(s2 = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}

char		*save_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char		*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(rtn = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int			get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save[1024];
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (reader && !check_has_new_line(save[fd]))
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (reader);
		}
		buff[reader] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	free(buff);
	*line = get_line(save[fd]);
	reader = (check_has_new_line(save[fd]) ? 1 : 0);
	save[fd] = save_save(save[fd]);
	return (reader);
}
