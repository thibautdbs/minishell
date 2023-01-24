/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:46:37 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/24 16:49:51 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/redirs.h"

void	my_subshell_destroy(t_subshell **psubshell)
{
	if (*psubshell == NULL)
		return ;
	my_cmd_destroy(&(*psubshell)->cmd);
	my_redirs_destroy(&(*psubshell)->redirs);
	ft_memdel(psubshell);
}
