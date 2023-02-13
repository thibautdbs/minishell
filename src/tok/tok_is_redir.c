/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_is_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:11:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/10 12:15:26 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/tok.h"

#include <stdbool.h>

bool	my_tok_is_redir(char const *str)
{
	t_tok_t	type;

	type = my_tok_type(str);
	if (type == LESS || type == LESSLESS || type == GREAT || type == GREATGREAT)
		return (true);
	return (false);
}
