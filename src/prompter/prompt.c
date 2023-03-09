/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:30:18 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/09 03:10:20 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/prompt.h"

#include <readline/readline.h> //readline
#include <readline/history.h> //readline
#include <unistd.h>
#include <limits.h>

#include "libft.h" //t_success
#include "minishell/cmd.h"
#include "minishell/envlst.h"
#include "minishell/parser.h"
#include "minishell/runner.h"

static char	*loc_readline_cwd(void);
static int	loc_process_cmd(char const *cmd, t_envlst **penvlst, int res);

int	my_prompt(t_envlst **penvlst)
{
	char	*buf;
	int		res;

	res = 0;
	while (1)
	{
		buf = loc_readline_cwd();
		if (buf == NULL)
		{
			ft_putendl_fd("exit", STDERR_FILENO);
			break ;
		}
		add_history(buf);
		res = loc_process_cmd(buf, penvlst, res);
		ft_memdel(&buf);
	}
	rl_clear_history();
	return (res);
}

static char	*loc_readline_cwd(void)
{
	char const		suffix[] = " minishell>";
	char			prompt[PATH_MAX + sizeof(suffix)];

	getcwd(prompt, PATH_MAX);
	ft_strlcat(prompt, suffix, sizeof(prompt));
	return (readline(prompt));
}

static int	loc_process_cmd(char const *cmd, t_envlst **penvlst, int res)
{
	t_cmdtree	*cmdtree;
	int			parse_res;
	// int			heredoc_res;

	parse_res = my_parse(cmd, &cmdtree);
	// heredoc_res = my_parse_heredoc(cmdtree);
	if (parse_res != 0)
	{
		my_cmdtree_del(&cmdtree);
		return (parse_res);
	}
	// if (heredoc_res != 0)
	// {
	// 	my_cmdtree_del(&cmdtree);
	// 	return (heredoc_res);
	// }
	res = my_run(cmdtree, penvlst, res, &cmdtree);
	my_cmdtree_del(&cmdtree);
	return (res);
}
