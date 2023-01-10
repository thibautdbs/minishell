/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:23:51 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:54:03 by tdubois          ###   ########.fr       */
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
	TOK_AST,
	TOK_AMP,
	TOK_PIPE,
	TOK_LPAR,
	TOK_RPAR,
	TOK_LANGL,
	TOK_RANGL,
	TOK_DBLQT,
	TOK_SGLQT,
	TOK_DOLLAR,
	TOK_QMARK,
	TOK_SPACES,
	TOK_WORD,
}	t_token_t;

typedef struct s_tok
{
	t_token_t		type;
	char			*content;
	struct s_tok	*next;
}	t_tok;

////////////////////////////////////////////////////////////////////////////////
/// FCTS

t_tok	*my_tok_extract(char const *input, size_t len, t_token_t type);
void	my_tok_destroy(t_tok **tok);

t_tok	**my_tok_2arr(t_tok *toks);

size_t	my_tok_size(t_tok const *toks);
t_tok	*my_tok_at(t_tok *toks, int idx);
bool	my_tok_contains(t_tok const *toks, t_token_t const *refs, size_t size);

void	my_tok_pop_front(t_tok **toks);
void	my_tok_pop_back(t_tok **toks);

#endif //TOKEN_H
