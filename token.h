/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:22:58 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/11 17:27:44 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

////////////////////////////////////////////////////////////////////////////////
/// TYPE DECLARATIONS

typedef enum e_tok_t	t_tok_t;
typedef struct s_tok	t_tok;

////////////////////////////////////////////////////////////////////////////////
/// TYPE DEFINITIONS

typedef enum e_tok_t
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

typedef struct s_tok
{
	t_tok_t	type;
	char	*content;
	t_tok	*next;
}	t_tok;

#endif //TOKEN_H
