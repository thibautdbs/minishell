/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelst_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:16:42 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/20 11:20:50 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/pipelst.h"

#include <stddef.h> //NULL

t_pipelst	*loc_pipelst_last(t_pipelst *pipelst)
{
	while (pipelst->next != NULL)
		pipelst = pipelst->next;
	return (pipelst);
}

void	my_pipelst_add_back(t_pipelst **pipes, t_pipelst *to_add)
{
	if (*pipes == NULL)
	{
		*pipes = to_add;
		return ;
	}
	loc_pipelst_last(*pipes)->next = to_add;
}
