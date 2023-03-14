/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:47:54 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/14 16:05:13 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <errno.h> //errno
#include <stdio.h> //perror
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "minishell/expand.h"
#include "minishell/redirlst.h"
#include "minishell/envlst.h"
#include "minishell/wordlst.h"

static int	loc_redirect_one(t_redirlst *redir, t_envlst *envlst, int res);
static int	loc_expand_filename(t_wordlst *word, char **ret_file_name,
				t_envlst *envlst, int res);

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
	char	*expanded_filename;

	if (redir->type == HEREDOC || redir->type == QTD_HEREDOC)
		return (my_redirect_one_heredoc(redir->word, redir->type, envlst, res));
	res = loc_expand_filename(redir->word, &expanded_filename, envlst, res);
	if (res != EXIT_SUCCESS)
		return (res);
	if (redir->type == APPND)
		res = my_redirect_one_appnd(expanded_filename);
	else if (redir->type == INFILE)
		res = my_redirect_one_infile(expanded_filename);
	else
		res = my_redirect_one_outfile(expanded_filename);
	ft_memdel(&expanded_filename);
	return (res);
}

static int	loc_expand_filename(t_wordlst *word, char **ret_file_name,
				t_envlst *envlst, int res)
{
	t_wordlst	*words;

	errno = 0;
	words = my_expand(word->content, envlst, res);
	if (errno != 0)
	{
		perror("minishell:");
		my_wordlst_del(&words);
		return (errno);
	}
	if (my_wordlst_size(words) != 1)
	{
		ft_putendl_fd("minishell: ambiguous redirect.", STDERR_FILENO);
		my_wordlst_del(&words);
		return (1);
	}
	*ret_file_name = words->content;
	words->content = NULL;
	my_wordlst_del(&words);
	return (EXIT_SUCCESS);
}
