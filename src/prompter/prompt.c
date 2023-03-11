/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:30:18 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/11 01:56:13 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/prompter.h"

#include <readline/readline.h> //readline
#include <readline/history.h> //readline
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h" //t_success
#include "minishell/cmd.h"
#include "minishell/envlst.h"
#include "minishell/parser.h"
#include "minishell/runner.h"
#include "minishell/utils.h"

static char	*loc_readline_cwd(void);
static int	loc_process_cmd(char const *cmd, t_envlst **penvlst, int res);

extern bool	g_sigint_received;

int	my_prompt(t_envlst **penvlst)
{
	char	*buf;
	int		res;

	res = 0;
	while (1)
	{
		buf = loc_readline_cwd();
		if (g_sigint_received == true)
		{
			res = 130;
			ft_memdel(&buf);
			continue ;
		}
		if (buf == NULL)
		{
			break ;
		}
		add_history(buf);
		res = loc_process_cmd(buf, penvlst, res);
		ft_memdel(&buf);
	}
	rl_clear_history();
	ft_putendl_fd("exit", STDERR_FILENO);
	return (res);
}

/** loc_readline_cwd: 
 *   calls readline with a prompt showing current working directory.
 */
static char	*loc_readline_cwd(void)
{
	char const		suffix[] = " minishell> ";
	char			prompt[PATH_MAX + sizeof(suffix)];

	if (getcwd(prompt, PATH_MAX) == NULL)
		prompt[0] = '\0';
	ft_strlcat(prompt, suffix, sizeof(prompt));
	g_sigint_received = false;
	return (readline(prompt));
}

static int	loc_process_cmd(char const *cmd, t_envlst **penvlst, int res)
{
	t_cmdtree	*cmdtree;
	int			parse_res;
	int			heredoc_res;

	parse_res = my_parse(cmd, &cmdtree);
	heredoc_res = my_prompt_heredocs(cmdtree);
	if (parse_res != EXIT_SUCCESS)
	{
		my_cmdtree_del(&cmdtree);
		return (parse_res);
	}
	if (heredoc_res != EXIT_SUCCESS)
	{
		my_cmdtree_del(&cmdtree);
		return (heredoc_res);
	}
	res = my_run(cmdtree, penvlst, res, &cmdtree);
	my_cmdtree_del(&cmdtree);
	return (res);
}
