/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:47:42 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/16 16:58:01 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "minishell/env.h"
#include "builtin/builtin_env.c"
#include "env/env_init.c"

typedef int			t_builtin(t_env *, char **args);
static	int			loc_builtin(t_builtin **builtins);

#define NBUILTINS 1

char const *builtins_ids[NBUILTINS] = {
	"env"
};

static	int	loc_builtin(t_builtin **builtins)
{
	builtins[0] = my_builtin_env;
	return (0);
};

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	t_builtin	*builtins[NBUILTINS];
	
	(void) argc;
	loc_builtin(builtins);
	env = my_env_init(envp);
	for (int i = 0; i < NBUILTINS; i++)
	{
		if (strcmp(argv[1], builtins_ids[i]) == 0)
		{
			return (builtins[0](env, argv + 1));
		}
	}
}
