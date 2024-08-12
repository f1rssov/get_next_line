/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:53:48 by kannie            #+#    #+#             */
/*   Updated: 2022/01/06 02:48:33 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_clean(char **line)
{
	free (*line);
	return (NULL);
}

char	*g_n_l(int fd, char *line, char *buf)
{
	int		number;
	char	*tmp;

	if (!line || !ft_strchr(line, '\n'))
	{
		number = read(fd, buf, BUFFER_SIZE);
		if (number == 0 && !line)
			return (ft_clean (&line));
		while (number > 0 && buf[0] != '\0')
		{
			buf[number] = '\0';
			if (!line)
				line = ft_substr(buf, 0, number);
			else
			{
				tmp = line;
				line = ft_strjoin(line, buf);
				free (tmp);
			}
			if (ft_strchr (line, '\n'))
				break ;
			number = read(fd, buf, BUFFER_SIZE);
		}
	}
	return (line);
}

char	*check_static(char **line)
{
	int		i;
	int		j;
	char	*tmp;
	char	*str;

	if (!ft_strchr(*line, '\n'))
	{
		str = ft_substr (*line, 0, ft_strlen(*line));
		free (*line);
		*line = NULL;
		if (str[0] == '\0')
			return (ft_clean(&str));
		return (str);
	}
	i = ft_strlen(*line);
	j = 0;
	tmp = *line;
	while (tmp[j] != '\n')
		j++;
	str = ft_substr(*line, 0, j + 1);
	*line = ft_substr(*line, j + 1, i - j + 1);
	free (tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;

	buf = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (fd >= 0 && BUFFER_SIZE > 0 && buf && read (fd, buf, 0) >= 0)
	{
		line = g_n_l(fd, line, buf);
		free(buf);
		if (!line)
			return (NULL);
		return ((check_static(&line)));
	}
	else
	{
		free (line);
		free (buf);
		return (NULL);
	}
}

int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	printf("1%s", get_next_line(fd));
	printf("2%s", get_next_line(fd));
	printf("3%s", get_next_line(fd));
	printf("4%s", get_next_line(fd));
	printf("5>%s", get_next_line(fd));
	printf("6>%s", get_next_line(fd));
	printf("7>%s", get_next_line(fd));
	printf("8>%s", get_next_line(fd));
	printf("9>%s", get_next_line(fd));
	printf("10>%s", get_next_line(fd));
	return (0);
}
