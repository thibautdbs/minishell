/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:42:51 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/09 16:23:44 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/heredoc.h"

#include <stddef.h> //NULL
#include <unistd.h>
#include <stdlib.h>//EXIT_SUCCESS

#include "minishell/cmd.h"
#include "minishell/redirlst.h"
#include "minishell/runner.h"

static int	loc_parse_connection(t_cmdtree *cmd);
static int	loc_parse_pipeline(t_cmdlst *pipeline);
static int	loc_parse_cmd(t_cmdlst *pipeline);
static int	loc_parse_redirs(t_redirlst *redir);

/** my_read_heredocs:
 *   browse cmdtree left to right and
 *   reads heredocs encountered along the way.
 */
int	my_read_heredocs(t_cmdtree *cmdtree)
{
	if (cmdtree == NULL)
		return (EXIT_SUCCESS);
	if (cmdtree->type == PIPELINE)
		return (loc_parse_pipeline(cmdtree->pipeline));
	return (loc_parse_connection(cmdtree));
}

/** loc_parse_connection:
 *   This fct is to be called on OR and AND nodes.
 *   Goes first into the left child and then into the one on the right.
 *   It permits heredoc to be handled left to right.
 */
static int	loc_parse_connection(t_cmdtree *cmd)
{
	int	res;

	res = my_read_heredocs(cmd->left);
	if (res != EXIT_SUCCESS)
		return (res);
	return (my_read_heredocs(cmd->right));
}

static int	loc_parse_pipeline(t_cmdlst *pipeline)
{
	int	res;

	while (pipeline != NULL)
	{
		res = loc_parse_cmd(pipeline);
		if (res != EXIT_SUCCESS)
			return (res);
		pipeline = pipeline->next;
	}
	return (EXIT_SUCCESS);
}

/** loc_parse_cmd:
 *   If cmd.type is SUBSHELL, goes first into subshell then handle redirs.
 *   It permits heredoc to be handled left to right.
 */
static int	loc_parse_cmd(t_cmdlst *cmd)
{
	int	res;

	if (cmd->type == SUBSHELL)
	{
		res = my_read_heredocs(cmd->subcmd);
		if (res != EXIT_SUCCESS)
			return (res);
	}
	return (loc_parse_redirs(cmd->redirs));
}

static int	loc_parse_redirs(t_redirlst *redirs)
{
	int	res;

	while (redirs != NULL)
	{
		if (redirs->type == HEREDOC)
		{
			res = my_read_heredoc(redirs);
			if (res != EXIT_SUCCESS)
				return (res);
		}
		redirs = redirs->next;
	}
	return (EXIT_SUCCESS);
}
