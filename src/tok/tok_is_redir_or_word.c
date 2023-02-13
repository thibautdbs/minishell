/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_is_redir_or_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:17:36 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/10 12:18:29 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/tok.h"

#include <stdbool.h>

bool	my_tok_is_redir_or_word(char const *str)
{
	return (my_tok_is_redir(str) || my_tok_type(str) == WORD);
}
