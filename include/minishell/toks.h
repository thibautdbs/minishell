/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:53:25 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 13:21:30 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKS_H
# define TOKS_H

# include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef struct s_toks	t_toks;
typedef enum e_tok_t	t_tok_t;
typedef union u_tok_v	t_tok_v;

typedef enum e_tok_t
{
	LPAR,
	RPAR,
	AND,
	OR,
	PIPE,
	VAR,
	QTD_VAR,
	INFILE,
	OUTFILE,
	APPNDFILE,
	WILDCARD,
	HEREDOC,
	BLANKS,
	WORD
}	t_tok_t;

typedef union u_tok_v
{
	char	*as_str;
	t_toks	*as_toks;
}	t_tok_v;

typedef struct s_toks
{
	t_tok_t	type;
	t_tok_v	val;
	t_toks	*next;
}	t_toks;

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

void	my_toks_del(t_toks **toks);
void	my_toks_del_one(t_toks **toks);

void	my_toks_add_back(t_toks **toks, t_toks *new_tok);

t_toks	*my_toks_last(t_toks *toks);

bool	my_toks_type_match(t_toks const *tok, t_tok_t const *types, int size);

#endif //TOKS_H
