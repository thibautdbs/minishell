/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_get_path.test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 16:38:15 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "libft.h"

#include "runner/run_get_path.c"

////////////////////////////////////////////////////////////////////////////////
/// HELPERS

char	*result;

static void	teardown(void *data)
{
	(void) data;
	ft_memdel(&result);
}

////////////////////////////////////////////////////////////////////////////////
/// TESTS

TEST	test_cmd_and_path_exist()
{
	char *args[] = {"wc", "-l", NULL}; 
	char *my_env[] = {"PATH=/usr/bin", "PROUT=wqfwq", NULL}; 
	result = my_get_path(args, my_env);
//	ASSERT_NEQ(NULL, result);
	ASSERT_STR_EQ("/usr/bin/wc", result);
	PASS();
}

TEST	test_wrong_path()
{
	char *args[] = {"wc", "-l", NULL}; 
	char *my_env[] = {"PATH=/usr/binrw3", "PROUT=wqfwq", NULL}; 
	result = my_get_path(args, my_env);
	ASSERT_EQ(NULL, result);
	PASS();
}

TEST	test_wrong_cmd()
{
	char *args[] = {"wceqqr", "-l", NULL}; 
	char *my_env[] = {"PATH=/usr/bin", "PROUT=wqfwq", NULL}; 
	result = my_get_path(args, my_env);
	ASSERT_EQ(NULL, result);
	PASS();
}

SUITE (run_get_path)
{
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test_cmd_and_path_exist);
	RUN_TEST(test_wrong_path);
	RUN_TEST(test_wrong_cmd);
}
