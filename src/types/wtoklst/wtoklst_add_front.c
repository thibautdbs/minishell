/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:20:33 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/03 16:22:32 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include <stddef.h>//NULL

void	my_wtoklst_add_front(t_wtoklst **ptoks, t_wtoklst *new)
{
	if (*ptoks != NULL)
		my_wtoklst_add_back(&new, *ptoks);
	*ptoks = new;
}
