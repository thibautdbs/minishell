/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:23:51 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 16:35:03 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stddef.h>//size_t
# include <stdbool.h>//bool

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef enum e_token_t
{
	TOK_OR,
	TOK_AND,
	TOK_PIPE,
	TOK_LPAR,
	TOK_RPAR,
	TOK_OUTPT,
	TOK_APPND,
	TOK_HRDOC,
	TOK_INPT,
	TOK_WORD,
	TOK_SPCS,
	TOK_QTS,
	TOK_AST,
	TOK_VAR
}	t_token_t;

typedef struct s_tok
{
	t_token_t		type;
	char			*content;
	struct s_tok	*next;
}	t_tok;

////////////////////////////////////////////////////////////////////////////////
/// FCTS

t_tok	*my_tok_create(t_token_t type, char const *content, int len);
void	my_tok_destroy(t_tok **tok);

t_tok	**my_tok_2arr(t_tok *toks);

int		my_tok_size(t_tok const *toks);
t_tok	*my_tok_at(t_tok *toks, int idx);
bool	my_tok_contains(t_tok const *toks, t_token_t const *refs, int size);

void	my_tok_add_back(t_tok **toks, t_tok *tok);

void	my_tok_pop_front(t_tok **toks);
void	my_tok_pop_back(t_tok **toks);

#endif //TOKEN_H
