/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:30:18 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 14:09:04 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //t_success
#include <stdio.h> //printf, readline
#include <readline/readline.h> //readline
#include <readline/history.h> //readline
#include <signal.h> //signal

#include "minishell/cmd.h"
#include "minishell/envlst.h"
#include "minishell/parser.h"
#include "minishell/runner.h"

int	sig_state;

static t_success	loc_check_args(int argc)
{
	if (argc > 1)
	{
		ft_puterr("Invalid args");
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	loc_prompt(char **envp)
{
	char				*buf;
	t_cmdtree_or_err	tree;
	t_envlst			*envlst;
	int					res;

	envlst = my_envlst_init(envp);
	res = 0;
	if (envlst == NULL)
		return ;
	while (1)
	{
		buf = readline("minishell > ");
		if (buf == NULL)
		{
			ft_putstr_fd("exit\n", 1);
			break ;
		}
		add_history(buf);
		tree = my_parse(buf);
		ft_memdel(&buf);
		if (tree.err == 0)
			res = my_run(tree.cmdtree, &envlst, res, &tree.cmdtree);
		else
			res = tree.err;
		my_cmdtree_del(&tree.cmdtree);
	}
	my_envlst_del(&envlst);
}

void	loc_sa_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void) argv;
	sig_state = 0;
	if (loc_check_args(argc) == FAILURE)
		return (1);
	signal(SIGINT,loc_sa_handler);
	loc_prompt(envp);
	rl_clear_history();
	return (0);
}
