/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:41:02 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/14 16:24:59 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"
#include "minishell/prompter.h"

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
static void	loc_puterr(char const *sep);
static bool	loc_perform_quote_removal(char *word);

extern t_globals	g_globals;

int	my_prompt_heredoc(t_redirlst *redir)
{
	int			res;
	t_wordlst	*sep;
	t_wordlst	*new_line;
	bool		performed_quote_removal;

	sep = my_wordlst_pop_front(&redir->word);
	performed_quote_removal = loc_perform_quote_removal(sep->content);
	if (performed_quote_removal)
		redir->type = QTD_HEREDOC;
	while (1)
	{
		res = loc_readline_as_word(&new_line);
		if (res != EXIT_SUCCESS)
			break ;
		if (new_line == NULL)
			loc_puterr(sep->content);
		if (new_line == NULL || ft_strcmp(sep->content, new_line->content) == 0)
		{
			my_wordlst_del(&new_line);
			break ;
		}
		my_wordlst_add_back(&redir->word, new_line);
	}
	my_wordlst_del(&sep);
	return (res);
}

static int	loc_readline_as_word(t_wordlst **ret_word)
{
	*ret_word = my_wordlst_new();
	if (*ret_word == NULL)
		return (ENOMEM);
	(*ret_word)->content = readline("> ");
	if (g_globals.did_receive_sigint == true)
	{
		my_wordlst_del(ret_word);
		return (130);
	}
	if ((*ret_word)->content == NULL)
		my_wordlst_del(ret_word);
	return (EXIT_SUCCESS);
}

static void	loc_puterr(char const *sep)
{
	ft_putstr_fd("minishell: warning: here-document ", STDERR_FILENO);
	ft_putstr_fd("delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(sep, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
}

static bool	loc_perform_quote_removal(char *word)
{
	bool	performed_quote_removal;
	int		len;
	char	sep[2];

	bzero(sep, sizeof(sep));
	performed_quote_removal = false;
	while (*word != '\0')
	{
		sep[0] = *word;
		if (sep[0] == '\'' || sep[0] == '\"')
		{
			performed_quote_removal = true;
			len = strcspn(word + 1, sep);
			memmove(word, word + 1, len);
			word += len;
			memmove(word, word + 2, strlen(word + 2) + 1);
		}
		else
			word += strcspn(word, "\'\"");
	}
	return (performed_quote_removal);
}
