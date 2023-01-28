/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:49:59 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/28 16:47:32 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //t_success
#include "stdio.h" //printf, readline
#include <readline/readline.h> //readline
#include <readline/history.h> //readline
#include <signal.h>

static t_success	loc_check_args(int argc)
{
	if (argc > 1)
	{
		ft_puterr("Invalid args");
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	loc_prompt(void)
{
	char	*buf;

	while (1)
	{
		buf = readline("kaminishell > ");
		if (buf == NULL) //CTRL + D
			break ;
		printf("%s", buf);
		ft_memdel(&buf);
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
	(void) envp;
	if (loc_check_args(argc) == FAILURE)
		return (0);
	signal(SIGINT,SIG_IGN);
	signal(SIGINT,loc_sa_handler);
	loc_prompt();
	return (0);
}
