/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdtree_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:07:41 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 15:15:42 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

#include "libft.h"//ft_memdel

void	my_cmdtree_del(t_cmdtree **pcmdtree)
{
	if (*pcmdtree == NULL)
		return ;
	if ((*pcmdtree)->type == PIPELINE)
	{
		my_cmdlst_del(&(*pcmdtree)->pipeline);
	}
	else
	{
		my_cmdtree_del(&(*pcmdtree)->left);
		my_cmdtree_del(&(*pcmdtree)->right);
	}
	ft_memdel(pcmdtree);
}
