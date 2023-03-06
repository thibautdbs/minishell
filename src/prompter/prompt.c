/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:30:18 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/06 13:18:43 by ffeaugas         ###   ########.fr       */
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

static t_success	loc_check_args(int argc)
{
	if (argc > 1)
	{
		ft_puterr("Invalid args");
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	loc_prompt(t_envlst *envlst)
{
	char				*buf;
	t_cmdtree_or_err	tree;
	int					res;

	res = 0;
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
}

static void	handler(int signum)
{
	// kill signum > child
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
	struct sigaction	sa;
	t_envlst	*envlst;

	(void) argv;
	sig_state = 0;
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (loc_check_args(argc) == FAILURE)
		return (1);
	envlst = my_envlst_init(envp);
	if (envlst == NULL)
		return (0);
	sigaction(SIGINT, &sa, NULL);
//	signal(SIGINT,loc_sa_handler);
//	signal(SIGQUIT, SIG_IGN);
	loc_prompt(envlst);
	my_envlst_del(&envlst);
	rl_clear_history();
	return (0);
}
