/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/24 12:24:41 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <unistd.h> //unlink, dup2, close
#include <fcntl.h> //open
#include <stdio.h> //readline
#include <readline/readline.h> //readline
#include <readline/history.h> //readline

#include "libft.h"//ft_memdel, ft_strlen, ft_strncmp

static t_success	loc_read_heredoc(char *delimiter, int fd)
{
	char	*buf;

	while (1)
	{
		buf = readline("> ");
		if (buf == NULL) //readline was interrupted by a signal
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
	close(fd);
	fd = open(".tmp.heredoc", O_RDONLY);
	return (SUCCESS);
}

t_success	my_open_heredoc(t_redir *redir)
{
	int	fd_heredoc;

//	if (my_check_redir_label(redir->name) == failure)
//		return (failure); //Invalid label
	fd_heredoc = open(".tmp.heredoc", O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd_heredoc < 0)
		return (FAILURE); //Error in opening
	if (loc_read_heredoc(redir->label, fd_heredoc) == FAILURE)
	{
		unlink(".tmp.heredoc");
		return (FAILURE); //Error in input : signal to abort prompt
	}
	dup2(fd_heredoc, STDIN);
	unlink(".tmp.heredoc");
	return (SUCCESS);
}
