/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdtree_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:13:43 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 16:16:01 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

#include "libft.h"

t_cmdtree	*my_cmdtree_new(t_cmdtree_t type)
{
	t_cmdtree	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmdtree));
	if (cmd == NULL)
		return (NULL);
	cmd->type = type;
	cmd->left = NULL;
	cmd->right = NULL;
	cmd->pipeline = NULL;
	return (cmd);
}
