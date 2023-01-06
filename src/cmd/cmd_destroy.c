/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:11:04 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/06 11:26:51 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>

#include "libft.h"

void	my_cmd_destroy(t_cmd **cmd)
{
	if (*cmd == NULL)
		return ;
	if ((*cmd)->type != CMD_EXEC)
	{
		my_cmd_destroy(&(*cmd)->left);
		my_cmd_destroy(&(*cmd)->right);
	}
	else 
		ft_strsdel(&(*cmd)->args);
	ft_memdel(cmd);
}
