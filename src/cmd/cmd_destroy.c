/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:50:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/23 14:28:32 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/toks.h"

static void	loc_destroy_smpl_cmd(t_smpl_cmd **psmpl_cmd);
static void loc_destroy_subshell(t_subshell **psubshell);
static void loc_destroy_cmd_lst(t_cmd_lst **pcmd_lst);

void	my_cmd_destroy(t_cmd **pcmd)
{
	if (*pcmd == NULL)
		return ;
	if ((*pcmd)->type == CMD_SMPL_CMD)
		loc_destroy_smpl_cmd(&(*pcmd)->val.as_smpl_cmd);
	else if ((*pcmd)->type == CMD_SUBSHELL)
		loc_destroy_subshell(&(*pcmd)->val.as_subshell);
	else
		loc_destroy_cmd_lst(&(*pcmd)->val.as_cmd_lst);
	ft_memdel(pcmd);
}

static void	loc_destroy_smpl_cmd(t_smpl_cmd **psmpl_cmd)
{
	if (*psmpl_cmd == NULL)
		return ;
	my_toks_del(&(*psmpl_cmd)->words);
	my_toks_del(&(*psmpl_cmd)->redirs);
	ft_memdel(psmpl_cmd);
}

static void loc_destroy_subshell(t_subshell **psubshell)
{
	if (*psubshell == NULL)
		return ;
	my_cmd_destroy(&(*psubshell)->cmd);
	ft_memdel(psubshell);
}

static void loc_destroy_cmd_lst(t_cmd_lst **pcmd_lst)
{
	if (*pcmd_lst == NULL)
		return ;
	loc_destroy_cmd_lst(&(*pcmd_lst)->next);
	my_cmd_destroy(&(*pcmd_lst)->cmd);
	ft_memdel(pcmd_lst);
}
