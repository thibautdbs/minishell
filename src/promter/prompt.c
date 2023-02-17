/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:30:18 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 12:41:33 by ffeaugas         ###   ########.fr       */
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

static void	loc_prompt(char **envp)
{
	char				*buf;
	t_cmdtree_or_err	tree;
	t_envlst			*envlst;
	int					res;

	envlst = my_envlst_init(envp);
	if (envlst == NULL)
		return ;
	while (1)
	{
		buf = readline("minishell > ");
		if (buf == NULL) //CTRL + D
			break ;
		tree = my_parse(buf);
		res = tree.err;
		ft_memdel(&buf);
		if (res == 0)
		{
			res = my_run(tree.cmdtree, &envlst, res, &tree.cmdtree);
			my_cmdtree_del(&tree.cmdtree);
			my_envlst_del(&envlst);
		}
	}
}

void	loc_sa_handler(int signum)
{
	if (signum == SIGINT)
		printf("je suis coincé");	
}

int	main(int argc, char **argv, char **envp)
{
	(void) argv;
	if (loc_check_args(argc) == FAILURE)
		return (1);
	signal(SIGINT,SIG_IGN);
	signal(SIGINT,loc_sa_handler);
	loc_prompt(envp);
	return (0);
}
