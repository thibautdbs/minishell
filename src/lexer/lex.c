/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:57:46 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 17:52:22 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>//NULL
#include <errno.h>
#include <stdio.h>

#include "libft.h"
#include "minishell/ctx.h"
#include "minishell/token.h"

#define NLEXERS 10

static void		loc_register_lexers(t_lexer **lexers);
static t_tok	*loc_extract_token(char const **input);

t_tok	*my_lex(char const *input)
{
	t_tok	*toks;
	t_tok	*curr;

	while (*input != '\0')
	{
		errno = 0;
		curr = loc_extract_token(&input);
		if (curr != NULL)
		{
			my_tok_add_back(&toks, curr);
			continue ;
		}
		if (errno != 0)
		{
			perror("minishell: lexer:");
			g_ctx->exitcode = ENOMEM;
		}
		my_tok_destroy(&toks);
		return (NULL);
	}
	return (toks);
}

static t_tok	*loc_extract_token(char const **input)
{
	int			i;
	char const	*keys = "&|()$\'\"<> ";
	t_lexer		*lexers[NLEXERS];

	loc_register_lexers(lexers);
	i = 0;
	while (i < NLEXERS - 1)
	{
		if (*input[0] == keys[i])
			return (lexers[i](input));
		i++;
	}
	return (lexers[NLEXERS - 1](input));
}

static void	loc_register_lexers(t_lexer **lexers)
{
	lexers[0] = my_lex_amp;
	lexers[1] = my_lex_pipe;
	lexers[2] = my_lex_left_par;
	lexers[3] = my_lex_right_par;
	lexers[4] = my_lex_dollar;
	lexers[5] = my_lex_single_quote;
	lexers[6] = my_lex_double_quote;
	lexers[7] = my_lex_left_angle_bracket;
	lexers[8] = my_lex_right_angle_bracket;
	lexers[9] = my_lex_spaces;
	lexers[10] = my_lex_word;
}
