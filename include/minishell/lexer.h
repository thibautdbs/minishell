/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:19:00 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 13:22:54 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "toks.h"

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef enum e_lex_error
{
	NO_ERR,
	MEM_ERR,
	LEX_ERR
}	t_lex_error;

typedef struct s_maybe_toks
{
	t_lex_error	err;
	t_toks		*toks;
}	t_maybe_toks;

typedef t_maybe_toks	t_lexer(char const **str);

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

t_maybe_toks	my_lex(char const *str);

#endif //LEXER_H
