/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:58:10 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 17:48:48 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"
# include "token.h"

////////////////////////////////////////////////////////////////////////////////
/// PUBLIC

t_tok	*my_lex(char const *input);

////////////////////////////////////////////////////////////////////////////////
/// PRIVATE

typedef t_tok	*t_lexer(char const **input);

t_tok	*my_lex_amp(char const **input);
t_tok	*my_lex_pipe(char const **input);

t_tok	*my_lex_left_par(char const **input);
t_tok	*my_lex_right_par(char const **input);

t_tok	*my_lex_dollar(char const **input);
t_tok	*my_lex_single_quote(char const **input);
t_tok	*my_lex_double_quote(char const **input);

t_tok	*my_lex_word(char const **input);
t_tok	*my_lex_spaces(char const **input);

t_tok	*my_lex_left_angle_bracket(char const **input);
t_tok	*my_lex_right_angle_bracket(char const **input);


#endif //LEXER_H
