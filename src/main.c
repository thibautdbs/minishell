/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:51:47 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/11 18:02:10 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

#include "libft.h"
#include "minishell/envlst.h"
#include "minishell/prompter.h"
#include "minishell/utils.h"

static void	loc_setup_signal_handling(void);
static void	loc_sigint_handler(int sig);
static int	loc_rl_event_hook(void);

bool	g_sigint_received;

int	main(int argc, char *argv[], char *envp[])
{
	int			res;
	t_envlst	*envlst;

	(void) argv;
	if (argc != 1)
	{
		ft_putendl_fd("minishell: did not expect any argument", STDERR_FILENO);
		return (1);
	}
	loc_setup_signal_handling();
	envlst = my_envlst_init(envp);
	if (envlst == NULL)
	{
		perror("minishell:");
		return (EXIT_FAILURE);
	}
	res = my_prompt(&envlst);
	my_envlst_del(&envlst);
	return (res);
}

static void	loc_setup_signal_handling(void)
{
	g_sigint_received = false;
	rl_event_hook = loc_rl_event_hook;
	my_signal(SIGINT, loc_sigint_handler);
	my_signal(SIGQUIT, SIG_IGN);
}

static void	loc_sigint_handler(int sig)
{
	(void) sig;
	g_sigint_received = true;
}

static int	loc_rl_event_hook(void)
{
	if (g_sigint_received == true)
		rl_done = 1;
	return (0);
}
