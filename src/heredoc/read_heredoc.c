/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:41:02 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/09 16:23:08 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/heredoc.h"

#include <readline/readline.h>//readline
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include "libft.h"
#include "minishell/redirlst.h"
#include "minishell/wordlst.h"
#include "minishell/utils.h"

static int	loc_readline_as_word(t_wordlst **ret_word);

extern bool	g_sigint_received;

int	my_read_heredoc(t_redirlst *redir)
{
	int			res;
	t_wordlst	*sep;
	t_wordlst	*new_line;

	sep = my_wordlst_pop_front(&redir->word);
	while (1)
	{
		res = loc_readline_as_word(&new_line);
		if (res != EXIT_SUCCESS)
		{
			my_wordlst_del(&sep);
			return (res);
		}
		if (new_line == NULL)
			ft_putendl_fd("minishell: TODO err heredoc", STDERR_FILENO);//TODO
		if (new_line == NULL || ft_strcmp(sep->content, new_line->content) == 0)
		{
			my_wordlst_del(&new_line);
			break ;
		}
		my_wordlst_add_back(&redir->word, new_line);
	}
	my_wordlst_del(&sep);
	return (EXIT_SUCCESS);
}

static int	loc_readline_as_word(t_wordlst **ret_word)
{
	int	res;

	*ret_word = my_wordlst_new();
	if (*ret_word == NULL)
		return (ENOMEM);
	res = my_interuptable_readline("> ", &(*ret_word)->content);
	if (res != EXIT_SUCCESS)
	{
		my_wordlst_del(ret_word);
		return (res);
	}
	if (g_sigint_received == true)
	{
		g_sigint_received = false;
		ft_putchar_fd('\n', STDOUT_FILENO);
		my_wordlst_del(ret_word);
		return (130);
	}
	if ((*ret_word)->content == NULL)
		my_wordlst_del(ret_word);
	return (EXIT_SUCCESS);
}
