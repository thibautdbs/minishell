/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:48:29 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 16:48:51 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

t_cmdlst	*my_cmdlst_last(t_cmdlst *cmdlst)
{
	while (cmdlst->next != NULL)
		cmdlst = cmdlst->next;
	return (cmdlst);
}
