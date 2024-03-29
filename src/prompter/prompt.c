/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:30:18 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/14 12:01:55 by tdubois          ###   ########.fr       */
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

extern t_globals	g_globals;

int	my_prompt(t_envlst **penvlst)
{
	char	*buf;
	int		res;

	res = 0;
	while (1)
	{
		g_globals.did_receive_sigint = false;
		buf = loc_readline_cwd();
		if (g_globals.did_receive_sigint == true)
		{
			res = 130;
			ft_memdel(&buf);
			continue ;
		}
		if (buf == NULL)
			break ;
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
 *   if cwd is subdirectory of $HOME, aliases $HOME with ~.
 */
static char	*loc_readline_cwd(void)
{
	char const		suffix[] = " minishell> ";
	char			prompt[PATH_MAX + sizeof(suffix)];
	char			*home;
	size_t			len;

	if (getcwd(prompt, PATH_MAX) == NULL)
		prompt[0] = '\0';
	ft_strlcat(prompt, suffix, sizeof(prompt));
	home = getenv("HOME");
	if (home == NULL)
		return (readline(prompt));
	len = ft_strlen(home);
	if (len == 0 || ft_strncmp(prompt, home, ft_strlen(home)) != 0)
		return (readline(prompt));
	prompt[len - 1] = '~';
	return (readline(prompt + len - 1));
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
	if (res < 0)
	{
		ft_putendl_fd("", STDOUT_FILENO);
		return (-res);
	}
	return (res);
}
