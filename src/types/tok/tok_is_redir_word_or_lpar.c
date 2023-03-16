/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_is_redir_word_or_lpar.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:20:19 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/10 12:20:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/tok.h"

#include <stdbool.h>

bool	my_tok_is_redir_word_or_lpar(char const *str)
{
	return (my_tok_is_redir_or_word(str) || my_tok_type(str) == LPAR);
}
