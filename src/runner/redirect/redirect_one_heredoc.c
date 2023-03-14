/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_one_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/14 16:29:48 by tdubois          ###   ########.fr       */
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
#include "minishell/envlst.h"
#include "minishell/redirlst.h"

static t_success	loc_tmpfile(int fds[2]);

static void			loc_expand_and_put_line(char *line, t_envlst *envlst,
						int res, int fd);
static int			loc_put_var(char *str, t_envlst *envlst, int fd);

/** my_redirect_one_heredoc:
 *   write heredoc lines into a temporary unnamed file under /tmp
 *   and redirects stdin toward this file.
 */
int	my_redirect_one_heredoc(t_wordlst const *lines, t_redirlst_t type,
		t_envlst *envlst, int res)
{
	int	fds[2];

	if (loc_tmpfile(fds) == FAILURE)
	{
		perror("minishell:");
		return (errno);
	}
	while (lines != NULL)
	{
		if (type == QTD_HEREDOC)
			ft_putendl_fd(lines->content, fds[1]);
		else
			loc_expand_and_put_line(lines->content, envlst, res, fds[1]);
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

static void	loc_expand_and_put_line(char *line, t_envlst *envlst, int res,
				int fd)
{
	while (*line != '\0')
	{
		if (*line != '$')
		{
			write(fd, line, ft_strcspn(line, "$"));
			line += ft_strcspn(line, "$");
			continue ;
		}
		line++;
		if (*line == '?')
		{
			ft_putnbr_fd(res, fd);
			line++;
		}
		else if (!ft_isalpha(*line) && *line != '_')
			ft_putstr_fd("$", fd);
		else
			line += loc_put_var(line, envlst, fd);
	}
	ft_putendl_fd("", fd);
}

static int	loc_put_var(char *str, t_envlst *envlst, int fd)
{
	int		len;
	char	*var;

	len = 0;
	while (ft_isdigit(str[len]) || ft_isalpha(str[len]) || str[len] == '_')
		len++;
	ft_memmove(str - 1, str, len);
	str[len - 1] = '\0';
	var = my_envlst_get_value(str - 1, envlst);
	if (var != NULL)
		ft_putstr_fd(var, fd);
	else
	{
		ft_putstr_fd("$", fd);
		ft_putstr_fd(str - 1, fd);
	}
	return (len);
}
