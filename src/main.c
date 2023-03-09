/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:51:47 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/09 13:02:37 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "minishell/envlst.h"
#include "minishell/prompt.h"

static void	loc_setup_signal_handling(void);
static void	loc_sigint_handler(int sig);

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
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	g_sigint_received = false;
	sa_sigint.sa_handler = loc_sigint_handler;
	sa_sigint.sa_flags = 0;
	sigemptyset(&sa_sigint.sa_mask);
	sigaction(SIGINT, &sa_sigint, NULL);
	sa_sigquit.sa_handler = SIG_IGN;
	sa_sigquit.sa_flags = 0;
	sigemptyset(&sa_sigquit.sa_mask);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

static void	loc_sigint_handler(int sig)
{
	(void) sig;
	g_sigint_received = true;
	close(STDIN_FILENO);
}
