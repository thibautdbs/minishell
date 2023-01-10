/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:58:10 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:53:28 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "token.h"

////////////////////////////////////////////////////////////////////////////////
/// PUBLIC

t_tok	*my_lex(char const *input);

////////////////////////////////////////////////////////////////////////////////
/// PRIVATE

typedef t_tok	*t_tokenizer(char const *);

t_tok	*my_lex_pipe(char const *input);
t_tok	*my_lex_and(char const *input);
t_tok	*my_lex_leftpar(char const *input);
t_tok	*my_lex_rightpar(char const *input);
t_tok	*my_lex_doublequote(char const *input);
t_tok	*my_lex_singlequote(char const *input);
t_tok	*my_lex_leftagbracket(char const *input);
t_tok	*my_lex_rightagbracket(char const *input);
t_tok	*my_lex_dollar(char const *input);
t_tok	*my_lex_qmark(char const *input);
t_tok	*my_lex_spaces(char const *input);
t_tok	*my_lex_word(char const *input);

#endif //LEXER_H
