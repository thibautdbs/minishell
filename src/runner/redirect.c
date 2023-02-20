/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:47:54 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/20 17:04:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <errno.h> //errno
#include <stdio.h> //perror

#include "libft.h"
#include "minishell/expand.h"
#include "minishell/redirlst.h"
#include "minishell/envlst.h"
#include "minishell/wordlst.h"

static int	loc_redir_one(t_redirlst *redir, t_envlst *envlst, int res);

int	my_redirect(t_redirlst *redir, t_envlst *envlst, int res)
{
	int			new_res;
	t_redirlst	*tmp;

	new_res = 0;
	while (redir != NULL)
	{
		tmp = redir;
		redir = redir->next;
		new_res = loc_redir_one(tmp, envlst, res);
		my_redirlst_del_one(&tmp);
		if (new_res != 0)
			break ;
	}
	return (new_res);
}

static int	loc_redir_one(t_redirlst *redir, t_envlst *envlst, int res)
{
	t_wordlst	*word;

	if (redir->type == HEREDOC)
		return (my_open_heredoc(redir->word->content));
	errno = 0;
	word = my_expand(redir->word->content, envlst, res); //TODO : add res is my_expand
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
