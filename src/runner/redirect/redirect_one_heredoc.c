/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_one_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/10 01:21:27 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <stdlib.h>
#include <unistd.h>//unlink, dup2, close
#include <fcntl.h> //open
#include <stdio.h>//perror
#include <errno.h>//errno
#include <limits.h>//PATH_MAX

#include "libft.h"//ft_memdel, ft_strlen, ft_strncmp, ft_count_digits
#include "minishell/wordlst.h"

static t_success	loc_tmpfile(int fds[2]);

/** my_redirect_one_heredoc:
 *   write heredoc lines into a temporary unnamed file under /tmp
 *   and redirects stdin toward this file.
 */
int	my_redirect_one_heredoc(t_wordlst const *lines)
{
	int	fds[2];

	if (loc_tmpfile(fds) == FAILURE)
	{
		perror("minishell:");
		return (errno);
	}
	while (lines != NULL)
	{
		ft_putendl_fd(lines->content, fds[1]);
		lines = lines->next;
	}
	dup2(fds[0], STDIN_FILENO);
	close(fds[0]);
	close(fds[1]);
	return (EXIT_SUCCESS);
}

#define HEREDOC_PREFIX "/tmp/heredoc."

/** loc_tmpfile:
 *   creates temporary unnamed file into tmp folder.
 *   on success, return SUCCESS and
 *   - sets fds[0] with a reading file descriptor.
 *   - sets fds[1] with a writing file descriptor.
 *   returns FAILURE on error.
 */
static t_success	loc_tmpfile(int fds[2])
{
	int		i;
	char	suffix[6];
	char	path[sizeof(HEREDOC_PREFIX) + sizeof(suffix)];

	i = 0;
	while (1)
	{
		if (ft_sitoa(suffix, i, sizeof(suffix)) == -1)
			return (FAILURE);
		ft_strlcpy(path, HEREDOC_PREFIX, sizeof(path));
		ft_strlcat(path, suffix, sizeof(path));
		errno = 0;
		fds[1] = open(path, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
		if (fds[1] != -1 || errno != EEXIST)
			break ;
		i++;
	}
	fds[0] = open(path, O_RDONLY);
	unlink(path);
	if (fds[0] == -1)
	{
		close(fds[1]);
		return (FAILURE);
	}
	return (SUCCESS);
}
