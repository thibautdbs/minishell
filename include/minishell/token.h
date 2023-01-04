/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:23:51 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/04 15:29:09 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stddef.h>//size_t

typedef struct s_token	t_token;

typedef enum e_token_type
{
	PIPE,
	AND,
	LEFTPAR,
	RIGHTPAR,
	DOUBLEQUOTE,
	SINGLQUOTE,
	LEFTAGBRACKET,
	RIGHTAGBRACKET,
	SPACES,
	WORD,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char const		*content;
	t_token			*next;
}	t_token;

t_token	*my_tok_extract(char const *input, size_t len);

#endif //TOKEN_H
