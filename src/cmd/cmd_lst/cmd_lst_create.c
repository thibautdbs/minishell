/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:57:44 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/16 17:26:14 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

#include "libft.h"

t_cmd_lst	*my_cmd_lst_create(t_cmd *cmd)
{
	t_cmd_lst	*cmd_lst;

	cmd_lst = ft_calloc(1, sizeof(t_cmd_lst));
	if (cmd_lst == NULL)
		return (NULL);
	cmd_lst->next = NULL;
	cmd_lst->cmd = cmd;
	return (cmd_lst);
}
