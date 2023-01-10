/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_right_par.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:41:27 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 17:50:25 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include "libft.h"
#include "minishell/ctx.h"
#include "minishell/token.h"

t_tok	*my_lex_right_par(char const **input)
{
	*input += 1;
	return (my_tok_create(TOK_RPAR, ")", 1));
}
