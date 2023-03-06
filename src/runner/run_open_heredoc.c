/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/06 17:27:59 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redirlst.h"
#include "minishell/runner.h"

#include <unistd.h>//unlink, dup2, close
#include <fcntl.h> //open
#include <stdio.h>//perror
#include <readline/readline.h>//readline
#include <errno.h>//errno
#include <limits.h>//PATH_MAX
#include "libft.h"//ft_memdel, ft_strlen, ft_strncmp, ft_count_digits
#include "minishell/wordlst.h"

//static int	loc_tmpfile(char *path);
//static int	loc_read_heredoc(char const *delimiter, int tmp_fd);

int	my_open_heredoc(t_redirlst *redir)
{
	char		*buf;
	t_wordlst	*new;

	errno = 0;
	while (errno == 0)
	{
		buf = readline("> ");
		if (buf == NULL)
			return (errno);
		if (ft_strcmp(buf, redir->word->content) == 0)
		{
			ft_memdel(&buf);
			return (0);
		}
		new = my_wordlst_new();
		new->content = ft_strdup(buf);
		my_wordlst_add_back(&redir->word, new);
		ft_memdel(&buf);
	}
	my_wordlst_pop_front(&redir->word);
	return (errno);
}

/*
int	my_open_heredoc(char const *str)
{
	int		tmp_fd;
	char	file_name[PATH_MAX];
	int		res;

	errno = 0;
	tmp_fd = loc_tmpfile(file_name);
	if (tmp_fd < 0)
	{
		perror("minishell: File creation failed");
		return (errno);
	}
	res = loc_read_heredoc(str, tmp_fd);
	close(tmp_fd);
	if (res == 0)
		res = my_open_input(file_name);
	unlink(file_name);
	return (res);
}

static int	loc_read_heredoc(char const *delimiter, int tmp_fd)
{
	char	*buf;

	while (1)
	{
		errno = 0;
		buf = readline("> ");
		if (buf == NULL)
			return (errno);
		if (ft_strcmp(buf, delimiter) == 0)
		{
			ft_memdel(&buf);
			return (0);
		}
		ft_putendl_fd(buf, tmp_fd);
		ft_memdel(&buf);
	}
	return (0);
}

static int	loc_tmpfile(char *path)
{
	char const	*prefix = "/tmp/heredoc.";
	int			fd;
	int			i;

	i = 0;
	while (1)
	{
		if (ft_strlen(prefix) + ft_count_digits(i) >= PATH_MAX)
			return (-1);
		ft_strlcpy(path, prefix, PATH_MAX);
		ft_strlcat(path, ft_itoa(i), PATH_MAX);
		errno = 0;
		fd = open(path, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
		if (fd != -1 || errno != EEXIST)
			return (fd);
		i++;
	}
}
*/
