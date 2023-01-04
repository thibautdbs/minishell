/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:57:46 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/04 19:51:19 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/token.h"

#define NTOKENIZERS 5

static void	loc_init_tokenizers(t_tokenizer **tokenizers);

t_token	*my_lex(char const *input)
{
	int			i;
	t_token		*token;
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
	tokenizers[0] = my_lex_word;
	tokenizers[1] = my_lex_pipe;
	tokenizers[2] = my_lex_and;
	tokenizers[3] = my_lex_leftpar;
	tokenizers[4] = my_lex_rightpar;
//	tokenizers[5] = my_lex_doublequote;
//	tokenizers[6] = my_lex_singlequote;
//	tokenizers[7] = my_lex_leftagbracket;
//	tokenizers[8] = my_lex_rightagbracket;
}
