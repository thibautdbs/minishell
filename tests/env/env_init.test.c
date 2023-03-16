/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/16 16:06:50 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest/greatest.h"

#include "libft.h"
#include <stdio.h>

#include "types/envlst/envlst_init.c"
#include "types/envlst/envlst_del.c"
#include "minishell/envlst.h"

////////////////////////////////////////////////////////////////////////////////
/// HELPERS

t_envlst	*env;

static void	teardown(void *data)
{
	(void) data;

	my_envlst_del(&env);
}

////////////////////////////////////////////////////////////////////////////////
/// ASSERTIONS

TEST	ASSERT_ENV_MATCH(t_envlst *env, char **ref_envp)
{
	int		i;
	t_envlst	*curr;

	curr = env;
	i = 0;
	while (ref_envp[i] != NULL)
	{
		ASSERT_STR_EQ(ref_envp[i], curr->content);
		i++;
		curr = curr->next;
	}
	ASSERT_EQ(NULL, curr);
	PASS();
}

////////////////////////////////////////////////////////////////////////////////
/// TESTS

TEST	basic1()
{
	char	*ref_envp[] = {"YO=crcrcr", "BZ=bzzz", "PROUT=proutprout", NULL};

	env = my_envlst_init(ref_envp);
	CHECK_CALL(ASSERT_ENV_MATCH(env, ref_envp));
	PASS();
}

SUITE (env_init)
{
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(basic1);
}
