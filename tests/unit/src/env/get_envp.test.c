/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/13 13:01:28 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "libft.h"
#include <stdio.h>

#include "env/get_envp.c"
#include "minishell/env.h"

////////////////////////////////////////////////////////////////////////////////
/// HELPERS

char	**envp;

static void	teardown(void *data)
{
	(void) data;
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_memdel(&envp[i]);
		i++;
	}
	ft_memdel(&envp);
}

////////////////////////////////////////////////////////////////////////////////
/// ASSERTIONS

TEST	ASSERT_ENV_MATCH(char **envp, t_env *ref_env)
{
	int		i;
	t_env	*curr;

	curr = ref_env;
	i = 0;
	while (envp[i] != NULL)
	{
		ASSERT_STR_EQ(curr->content, envp[i]);
		i++;
		curr = curr->next;
	}
	ASSERT_EQ(NULL, envp[i]);
	PASS();
}

////////////////////////////////////////////////////////////////////////////////
/// TESTS

TEST	basic1()
{
	t_env	ref_env3 = {"LOL=PROUT", NULL};
	t_env	ref_env2 = {"YO=yoooooooooo", &ref_env3};
	t_env	ref_env1 = {"BZZZZ=bz", &ref_env2};

	envp = my_get_envp(&ref_env1);
	CHECK_CALL(ASSERT_ENV_MATCH(envp, &ref_env1));
	PASS();
}

SUITE (get_envp)
{
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(basic1);
}
