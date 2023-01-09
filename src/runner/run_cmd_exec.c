/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:42:42 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/09 15:44:46 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include "libft.h"

#include "minishell/cmd.h"

//4 étapes :
//* Ouvrir les redirections
//* Check si la commande est un built-in, si oui on l'execute et on s'arrête là
//* Recupère le path de la commande
//* Execute la commande
t_success	ft_run_exec_cmd(t_cmd	**root, t_cmd *cmd)
{
	int		error_status;
	char	*path;
	char	**args;

	error_status = my_run_open_redir(cmd->redirs);
	if (error_status == failure) //2 cas : file invalide ou open fail
		return (failure);
//	if (my_run_built-in(cmd->args))
//		return (success);
	path = my_run_get_path(cmd->args, ctx->env)
	if (path == NULL) //2 cas : commande invalide ou calloc fail
		return (failure);
	my_cmd_destroy(root);
	execve(path, args, ft_env_build(ctx->env));
}
