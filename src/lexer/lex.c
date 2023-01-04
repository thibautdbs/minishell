/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:57:46 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/04 15:19:54 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/token.h"

#define NTOKENIZERS 1

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
}
