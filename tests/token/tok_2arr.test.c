/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_2arr.test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:42:21 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 15:07:07 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "libft.h"
#include "minishell/token.h"

static t_token	**arr;

static void	teardown(void *data)
{
	(void) data;
	ft_memdel(&arr);
}

TEST basic()
{
	t_token	tok4 = {AND, "&", NULL};
	t_token	tok3 = {WORD, "salut", &tok4};
	t_token	tok2 = {SPACES, "   ", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};
	
	arr = my_tok_2arr(&tok1);

	ASSERT_EQ(&tok1, arr[0]);
	ASSERT_EQ(&tok2, arr[1]);
	ASSERT_EQ(&tok3, arr[2]);
	ASSERT_EQ(&tok4, arr[3]);
	PASS();
}

SUITE (tok_2arr)
{
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(basic);
}
