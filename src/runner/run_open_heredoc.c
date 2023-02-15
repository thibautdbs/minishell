/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 12:54:50 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <linux/limits.h>
#include <unistd.h> //unlink, dup2, close
#include <fcntl.h> //open
#include <stdio.h> //readline
#include <readline/readline.h> //readline
#include <readline/history.h> //readline
#include <errno.h> //errno
#include <limits.h> //PATH_MAX

#include "libft.h"//ft_memdel, ft_strlen, ft_strncmp, ft_count_digits

static int			loc_tmpfile(char *path);
static t_success	loc_get_path(char *path, char *str, int index);

static t_success	loc_read_heredoc(char *delimiter, int fd)
{
	char	*buf;

	while (1)
	{
		buf = readline("> ");
		if (buf == NULL)
		{
			ft_memdel(&buf);
			return (FAILURE);
		}
		if (ft_strncmp(buf, delimiter, ft_strlen(delimiter)) == 0
			&& buf[ft_strlen(delimiter)] == '\n')
		{
			ft_memdel(&buf);
			break ;
		}
		write (fd, buf, ft_strlen(buf));
		ft_memdel(&buf);
	}
	return (SUCCESS);
}

int	my_open_heredoc(char *str)
{
	int		fd;
	char	file_name[PATH_MAX];

	errno = 0;
	fd = loc_tmpfile(file_name);
	if (fd < 0)
		perror("File creation failed");
	if (errno == 0 && loc_read_heredoc(str, fd) == FAILURE)
		unlink(file_name);
	if (errno == 0)
	{
		close(fd);
		fd = open(file_name, O_RDONLY);
		dup2(fd, STDIN);
		if (errno != 0)
		{
			perror("Dup error");
			close(fd);
		}
		else
			unlink(file_name);
	}
	return (errno);
}

static int	loc_tmpfile(char *path)
{
	int	fd;
	int	i;

	i = 0;
	while (1)
	{
		if (loc_get_path(path, "/tmp/tmp%i", i) == FAILURE)
			return (-1);
		errno = 0;
		fd = open(path, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
		if (fd != -1 || errno != EEXIST)
			return (fd);
		i++;
	}
}

static t_success	loc_get_path(char *path, char *str, int index)
{
	if (ft_strlen(str) + ft_count_digits(index) >= PATH_MAX)
		return (FAILURE);
	ft_strlcpy(path, str, PATH_MAX);
	ft_strlcat(path, ft_itoa(index), PATH_MAX);
	return (SUCCESS);
}
