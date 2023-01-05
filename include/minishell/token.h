/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:23:51 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 20:26:02 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stddef.h>//size_t
# include <stdbool.h>//bool

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef struct s_token	t_token;

typedef enum e_token_type
{
	PIPE,
	AND,
	LEFTPAR,
	RIGHTPAR,
	DOUBLEQUOTE,
	SINGLEQUOTE,
	LEFTAGBRACKET,
	RIGHTAGBRACKET,
	DOLLAR,
	QMARK,
	SPACES,
	WORD,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char const		*content;
	t_token			*next;
}	t_token;

////////////////////////////////////////////////////////////////////////////////
/// FCTS

t_token	*my_tok_extract(char const *input, size_t len, t_token_type type);
void	my_tok_destroy(t_token **tok);

t_token	**my_tok_2arr(t_token *toks);

size_t	my_tok_size(t_token const *toks);
t_token	*my_tok_at(t_token *toks, int idx);
bool	my_tok_contains(t_token const *toks, t_token_type const *refs, size_t size);

void    my_tok_pop_front(t_token **toks);
void    my_tok_pop_back(t_token **toks);

#endif //TOKEN_H
