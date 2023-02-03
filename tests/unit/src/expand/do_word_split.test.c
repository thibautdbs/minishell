/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_word_split.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:06:46 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/03 14:22:45 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "minishell/expand.h"
#include "minishell/wtoklst.h"

////////////////////////////////////////////////////////////////////////////////
/// SETUP

static t_wtoklst	*actual;

static void	setup(void *data)
{
	(void) data;
	actual = NULL;
}

static void	teardown(void *data)
{
	(void) data;
	my_wtoklst_del(&actual);
}

TEST	ASSERT_WTOKLST_EQ(t_wtoklst const *expected, t_wtoklst const *actual)
{
	while (expected != NULL)
	{
		ASSERT_NEQ(NULL, actual);
		if (expected->content == NULL)
			ASSERT_EQ(NULL, actual->content);
		else
			ASSERT_STR_EQ(expected->content, actual->content);
		expected = expected->next;
		actual = actual->next;
	}
	ASSERT_EQ(NULL, actual);
	PASS();
}

////////////////////////////////////////////////////////////////////////////////
/// TESTS

TEST	basic1(void)
{
	t_wtoklst	tok0 = { .type = CHARS, .content = "word", .next = NULL};

	t_wtoklst	*expected = &tok0;

	actual = my_do_word_split("word", " \t\n");

	CHECK_CALL(ASSERT_WTOKLST_EQ(expected, actual));
	PASS();
}

TEST	basic2(void)
{
	t_wtoklst	tok1 = { .type = CHARS, .content = "word", .next = NULL};
	t_wtoklst	tok0 = { .type = BLANKS, .content = NULL, .next = &tok1};

	t_wtoklst	*expected = &tok0;

	actual = my_do_word_split("   word", " \t\n");

	CHECK_CALL(ASSERT_WTOKLST_EQ(expected, actual));
	PASS();
}

SUITE(suite_do_word_split)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(basic1);
	RUN_TEST(basic2);
}
