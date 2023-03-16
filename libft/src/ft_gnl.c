/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:25:42 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/29 17:38:42 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

#undef OPEN_MAX
#define OPEN_MAX 20

static ssize_t	read_str(int fd, char *buf);
static void		append_line(char **str, char *buf, size_t size);
static void		save_next_lines(char *buf, size_t size);

char	*ft_gnl(int fd)
{
	char		*line;
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1] = {""};
	ssize_t		size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf[fd][0] == '\0')
		size = read_str(fd, buf[fd]);
	if (buf[fd][0] == '\0')
		return (NULL);
	size = ft_strcspn(buf[fd], "\n") + 1;
	line = ft_strndup(buf[fd], size);
	while (line != NULL && buf[fd][size - 1] != '\n')
	{
		size = read_str(fd, buf[fd]);
		if (size == -1)
			free(line);
		if (size == -1 || size == 0)
			break ;
		append_line(&line, buf[fd], size);
	}
	if (line == NULL || size == -1)
		return (NULL);
	save_next_lines(buf[fd], size);
	return (line);
}

static ssize_t	read_str(int fd, char *buf)
{
	ssize_t	size;

	size = read(fd, buf, BUFFER_SIZE);
	if (size <= 0)
	{
		buf[0] = '\0';
		return (size);
	}
	buf[size] = '\0';
	return (ft_strcspn(buf, "\n") + 1);
}

static void	append_line(char *(*str), char *buf, size_t size)
{
	char			*new_str;
	size_t const	str_len = ft_strlen(*str);

	if (buf[size - 1] == '\n')
		new_str = (char *) malloc((str_len + size + 1) * sizeof(char));
	else
		new_str = (char *) malloc((str_len + size) * sizeof(char));
	if (new_str == NULL)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	ft_strlcpy(new_str, *str, str_len + 1);
	ft_strlcpy(new_str + str_len, buf, size + 1);
	free(*str);
	*str = new_str;
}

static void	save_next_lines(char *buf, size_t size)
{
	if (buf[size - 1] == '\n')
	{
		ft_memmove(buf, buf + size, ft_strlen(buf + size) + 1);
		return ;
	}
	buf[0] = '\0';
}
