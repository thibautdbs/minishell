/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:54:18 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/16 16:56:20 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

t_cmd_lst	*my_cmd_lst_last(t_cmd_lst *cmd_lst)
{
	while (cmd_lst != NULL)
		cmd_lst = cmd_lst->next;
	return (cmd_lst);
}
