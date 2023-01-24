/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:48:31 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/16 10:39:30 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

void	my_cmd_lst_add_back(t_cmd_lst **cmd_lst, t_cmd_lst *new_cmd)
{
	if (*cmd_lst == NULL)
	{
		*cmd_lst = new_cmd;
		return ;
	}
	my_cmd_lst_last(*cmd_lst)->next = new_cmd;
}
