/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:16:58 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/11 23:47:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKS_H
# define TOKS_H

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef enum
{
	LPAR,
	RPAR,
	LESS,
	LESSLESS,
	GREAT,
	GREATGREAT,
	ANDAND,
	BAR,
	BARBAR,
	WORD
}	t_tok_t;

typedef struct s_toks
{
	t_tok_t			type;
	char			*content;
	struct s_toks	*next;
}	t_toks;

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

void	my_toks_destroy(t_toks	**toks);

void	my_toks_add_back(t_toks **toks, t_toks *new_tok);

t_toks	*my_toks_last(t_toks *toks);

#endif //TOKS_H
