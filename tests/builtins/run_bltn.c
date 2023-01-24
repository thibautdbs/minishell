/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:47:42 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/20 11:18:56 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

typedef int	t_builtin(char **args, char **envp);

static int	test_builtin(char **args, char **envp)
{
	(void)args;
	(void)envp;
	printf("yoyoyo");
	return (0);
}

#define NBUILTINS 1

static char const	*builtins_ids[NBUILTINS] = {
	"test_builtin"
};

static t_builtin	*builtins[NBUILTINS] = {
	test_builtin
};

static int	run_builtin(int idx, char **argv, char **envp)
{
	return (builtins[idx](argv, envp));
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 2)
	{
		dprintf(2, "Error: not enough arguments.");
		return (1);
	}
	for (int i = 0; i < NBUILTINS; i++)
	{
		if (strcmp(argv[1], builtins_ids[i]) == 0)
		{
			return (run_builtin(i, argv + 1, envp));
		}
	}
	dprintf(2, "Error: couldn't find builtin `%s`.", argv[1]);
	return (1);
}
