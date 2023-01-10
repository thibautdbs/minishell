/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:57:46 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:29:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/token.h"

#define NTOKENIZERS 12

static void	loc_init_tokenizers(t_tokenizer **tokenizers);

t_tok	*my_lex(char const *input)
{
	int			i;
	t_tok		*token;
	t_tokenizer	*tokenizers[NTOKENIZERS];

	loc_init_tokenizers(tokenizers);
	if (*input == '\0')
		return (NULL);
	i = 0;
	while (i < NTOKENIZERS)
	{
		token = tokenizers[i](input);
		if (token != NULL)
			return (token);
		i++;
	}
	return (NULL);
}

static void	loc_init_tokenizers(t_tokenizer **tokenizers)
{
	tokenizers[0] = my_lex_pipe;
	tokenizers[1] = my_lex_and;
	tokenizers[2] = my_lex_leftpar;
	tokenizers[3] = my_lex_rightpar;
	tokenizers[4] = my_lex_doublequote;
	tokenizers[5] = my_lex_singlequote;
	tokenizers[6] = my_lex_leftagbracket;
	tokenizers[7] = my_lex_rightagbracket;
	tokenizers[8] = my_lex_dollar;
	tokenizers[9] = my_lex_qmark;
	tokenizers[10] = my_lex_spaces;
	tokenizers[11] = my_lex_word;
}
