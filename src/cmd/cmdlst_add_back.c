/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:35:42 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 16:46:18 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

void	my_cmdlst_add_back(t_cmdlst **pcmdlst, t_cmdlst *new)
{
	if (*pcmdlst == NULL)
	{
		*pcmdlst = new;
		return ;
	}
	my_cmdlst_last(*pcmdlst)->next = new;
}
