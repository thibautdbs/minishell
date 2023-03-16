/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:14:00 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/03 12:59:30 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include <stddef.h>//NULL

void	my_wtoklst_add_back(t_wtoklst **ptoks, t_wtoklst *new)
{
	if (*ptoks == NULL)
	{
		*ptoks = new;
		return ;
	}
	my_wtoklst_last(*ptoks)->next = new;
}
