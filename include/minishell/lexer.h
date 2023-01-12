/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:19:00 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 17:46:31 by tdubois          ###   ########.fr       */
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

t_maybe_toks	my_lex_lpar(char const **str);
t_maybe_toks	my_lex_rpar(char const **str);
t_maybe_toks	my_lex_less(char const **str);
t_maybe_toks	my_lex_great(char const **str);
t_maybe_toks	my_lex_amp(char const **str);
t_maybe_toks	my_lex_bar(char const **str);
t_maybe_toks	my_lex_dollar(char const **str);
t_maybe_toks	my_lex_ast(char const **str);
t_maybe_toks	my_lex_blanks(char const **str);
t_maybe_toks	my_lex_sgl_quotes(char const **str);
t_maybe_toks	my_lex_dbl_quotes(char const **str);
t_maybe_toks	my_lex_word(char const **str);

#endif //LEXER_H
