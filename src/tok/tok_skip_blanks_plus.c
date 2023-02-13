/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_skip_blanks_plus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:50:45 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/10 12:51:36 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/tok.h"

void	my_tok_skip_blanks_plus(const char **pstr, int n)
{
	my_tok_skip_blanks(pstr);
	*pstr += n;
}
