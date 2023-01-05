/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_at.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:42:21 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 14:58:50 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "minishell/token.h"

TEST positive_idxs()
{
	t_token	tok4 = {AND, "&", NULL};
	t_token	tok3 = {WORD, "salut", &tok4};
	t_token	tok2 = {SPACES, "   ", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};

	ASSERT_EQ(&tok1, my_tok_at(&tok1, 0));
	ASSERT_EQ(&tok2, my_tok_at(&tok1, 1));
	ASSERT_EQ(&tok3, my_tok_at(&tok1, 2));
	ASSERT_EQ(&tok4, my_tok_at(&tok1, 3));
	PASS();
}

TEST negative_idxs()
{
	t_token	tok4 = {AND, "&", NULL};
	t_token	tok3 = {WORD, "salut", &tok4};
	t_token	tok2 = {SPACES, "   ", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};

	ASSERT_EQ(&tok1, my_tok_at(&tok1, -4));
	ASSERT_EQ(&tok2, my_tok_at(&tok1, -3));
	ASSERT_EQ(&tok3, my_tok_at(&tok1, -2));
	ASSERT_EQ(&tok4, my_tok_at(&tok1, -1));
	PASS();

}

SUITE (tok_at)
{
	RUN_TEST(positive_idxs);
	RUN_TEST(negative_idxs);
}
