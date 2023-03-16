/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:17:06 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/09 01:23:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

#include "libft.h"

t_cmdlst	*my_cmdlst_new(t_cmdlst_t type)
{
	t_cmdlst	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmdlst));
	if (cmd == NULL)
		return (NULL);
	cmd->type = type;
	return (cmd);
}
