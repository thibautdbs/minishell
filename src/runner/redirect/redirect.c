/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:47:54 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/10 01:08:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <errno.h> //errno
#include <stdio.h> //perror
#include <stdlib.h>

#include "libft.h"
#include "minishell/expand.h"
#include "minishell/redirlst.h"
#include "minishell/envlst.h"
#include "minishell/wordlst.h"

static int	loc_redirect_one(t_redirlst *redir, t_envlst *envlst, int res);

int	my_redirect(t_redirlst *redir, t_envlst *envlst, int res)
{
	if (redir == NULL)
		return (EXIT_SUCCESS);
	while (redir != NULL)
	{
		res = loc_redirect_one(redir, envlst, res);
		if (res != EXIT_SUCCESS)
			return (res);
		redir = redir->next;
	}
	return (res);
}

static int	loc_redirect_one(t_redirlst *redir, t_envlst *envlst, int res)
{
	t_wordlst	*word;

	if (redir->type == HEREDOC)
		return (my_redirect_one_heredoc(redir->word));
	errno = 0;
	word = my_expand(redir->word->content, envlst, res);
	if (errno != 0)
	{
		perror("minishell:");
		res = errno;
	}
	else if (my_wordlst_size(word) != 1)
	{
		ft_puterr("minishell: ambiguous redirect.");
		res = 1;
	}
	else if (redir->type == APPND)
		res = my_open_append(word->content);
	else if (redir->type == INFILE)
		res = my_open_input(word->content);
	else
		res = my_open_output(word->content);
	my_wordlst_del(&word);
	return (res);
}
