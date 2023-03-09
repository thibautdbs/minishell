/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlst_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:33:16 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 15:56:53 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

#include "libft.h"

void	my_cmdlst_del_one(t_cmdlst **pcmdlst)
{
	if (*pcmdlst == NULL)
		return ;
	my_redirlst_del(&(*pcmdlst)->redirs);
	if ((*pcmdlst)->type == SIMPLECMD)
		my_wordlst_del(&(*pcmdlst)->words);
	else
		my_cmdtree_del(&(*pcmdlst)->subcmd);
	ft_memdel(pcmdlst);
}
