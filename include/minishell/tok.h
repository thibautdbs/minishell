/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:36:23 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/10 12:51:46 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOK_H
# define TOK_H

# include <stdbool.h>

typedef enum e_tok_t
{
	EOS,
	WORD,
	LESS,
	LESSLESS,
	GREAT,
	GREATGREAT,
	BAR,
	BARBAR,
	AMPAMP,
	LPAR,
	RPAR
}	t_tok_t;

void	my_tok_skip_blanks(char const **pstr);
void	my_tok_skip_blanks_plus(const char **pstr, int n);
t_tok_t	my_tok_type(char const *str);
bool	my_tok_is_blank(char const *str);
bool	my_tok_is_redir(char const *str);
bool	my_tok_is_redir_or_word(char const *str);
bool	my_tok_is_redir_word_or_lpar(char const *str);

#endif //TOK_H
