/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:42:51 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:02 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h> //NULL
#include <unistd.h>

#include "minishell/cmd.h"
#include "minishell/redirlst.h"
#include "minishell/runner.h"

static int	loc_parse_heredoc_or_and(t_cmdtree *cmd);
static int	loc_parse_heredoc_pipeline(t_cmdlst *pipeline);
static int	loc_parse_heredoc_cmd(t_cmdlst *pipeline);
static int loc_parse_heredoc_redirect(t_redirlst *redir);

int	my_parse_heredoc(t_cmdtree *cmd)
{
	if (cmd == NULL)
		return (0);
	if (cmd->type == OR || cmd->type == AND)
		return (loc_parse_heredoc_or_and(cmd));
	if (my_cmdlst_size(cmd->pipeline) == 1)
		return (loc_parse_heredoc_cmd(cmd->pipeline));
	return (loc_parse_heredoc_pipeline(cmd->pipeline));
}

static int	loc_parse_heredoc_or_and(t_cmdtree *cmd)
{
	int	res_left;
	int	res_right;

	res_left = my_parse_heredoc(cmd->left);
	res_right = my_parse_heredoc(cmd->right);
	if (res_left != 0)
		return (res_left);
	return (res_right);
}

static int	loc_parse_heredoc_pipeline(t_cmdlst *pipeline)
{
	int res;
	int	res_tmp;

	res = 0;
	while (pipeline != NULL)
	{
		res_tmp = loc_parse_heredoc_cmd(pipeline);
		if (res_tmp != 0)
			res = res_tmp;
		pipeline = pipeline->next;
	}
	return (res);
}

static int	loc_parse_heredoc_cmd(t_cmdlst *pipeline)
{
	int	res;
	int	res_tmp;

	res = loc_parse_heredoc_redirect(pipeline->redirs);
	if (pipeline->type == SIMPLECMD)
		return (res);
	res_tmp = my_parse_heredoc(pipeline->subcmd);
	if (res_tmp != 0)
		res = res_tmp;
	return (res);
}

static int loc_parse_heredoc_redirect(t_redirlst *redir)
{
	int	res;
	int	res_tmp;

	res = 0;
	while (redir != NULL)
	{
		if (redir->type == HEREDOC)
		{
			res_tmp = my_open_heredoc(redir);
			if (res_tmp != 0)
				res = res_tmp;
		}
		redir = redir->next;
	}
	return (res);
}
