/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:47:42 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/16 15:24:34 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "minishell/env.h"
#include "builtin/builtin_env.c"


typedef int	t_builtin(char **argv, char **envp);

#define NBUILTINS 2

char const *builtins_ids[NBUILTINS] = {
	"env"
};

t_builtin	*builtins[NBUILTINS] = {
	my_builtin_env
};

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	for (int i = 0; i < NBUILTINS; i++)
	{
		if (strcmp(argv[i], builtins_ids[i]) == 0)
		{
			return (builtins[i](argv, envp));
		}
	}
}
