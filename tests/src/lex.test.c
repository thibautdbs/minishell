/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/04 17:38:00 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "lexer/lex.c"
#include "minishell/lexer.h"
#include "minishell/token.h"

////////////////////////////////////////////////////////////////////////////////
/// HELPERS

static	t_token	*mine;

static void	teardown(void *data)
{
	(void) data;
	// destroy tokens
}

////////////////////////////////////////////////////////////////////////////////
/// ASSERTIONS

TEST ASSERT_TOKENS_MATCH(t_token const *ref, t_token const *mine)
{
	while (ref != NULL)
	{
		ASSERT_STR_EQ(ref->content, mine->content);
		ASSERT_EQ_FMT(ref->type, mine->type, "%i");
		ASSERT_NEQ(NULL, mine);
		ref = ref->next;
		mine = mine->next;
	}
	ASSERT_EQ(NULL, mine);
	PASS();
}

////////////////////////////////////////////////////////////////////////////////
/// TESTS

TEST basic1()
{
	t_token	tok3 = {WORD, "bzz", NULL};
	t_token	tok2 = {PIPE, "|", &tok3};
	t_token	tok1 = {WORD, "wesh", &tok2};

	mine = my_lex("wesh|bzz");
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	PASS();
}

SUITE (lex)
{
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(basic1);
}
