/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlst_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:28:44 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 17:29:53 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wordlst.h"

#include <stddef.h>//NULL

void	my_wordlst_add_back(t_wordlst **pwords, t_wordlst *new)
{
	if (*pwords == NULL)
	{
		*pwords = new;
		return ;
	}
	my_wordlst_last(*pwords)->next = new;
}
