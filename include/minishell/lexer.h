/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:58:10 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/04 15:02:14 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell/token.h"

////////////////////////////////////////////////////////////////////////////////
/// PUBLIC

t_token	*my_lex(char const *input);

////////////////////////////////////////////////////////////////////////////////
/// PRIVATE

typedef t_token	*t_tokenizer(char const *);

t_token	*my_lex_word(char const *input);
t_token	*my_lex_pipe(char const *input);

#endif //LEXER_H
