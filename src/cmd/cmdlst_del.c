/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:18:04 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 15:33:30 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

void	my_cmdlst_del(t_cmdlst **pcmdlst)
{
	t_cmdlst	*tmp;

	while (*pcmdlst != NULL)
	{
		tmp = my_cmdlst_pop_front(pcmdlst);
		my_cmdlst_del_one(&tmp);
	}
}
