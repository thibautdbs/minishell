/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_pop.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 17:00:33 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "lexer/lex.c"
#include "minishell/lexer.h"
#include "minishell/token.h"

////////////////////////////////////////////////////////////////////////////////
/// HELPERS

/*
static	t_token	*mine;

static void	teardown(void *data)
{
	(void) data;
	my_tok_destroy(&mine);
}
*/

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

TEST	test_basic1()
{
	t_token	tok5 = {SPACES, " ", NULL};
	t_token	tok4 = {RIGHTPAR, ")", &tok5};
	t_token	tok3 = {WORD, "oo", &tok4};
	t_token	tok2 = {LEFTPAR, "(", &tok3};
	t_token	tok1 = {SPACES, " ", &tok2};

	t_token *tok;
	tok = &tok1;
	my_tok_pop_front(&tok);
//	my_tok_pop_back(&tok);
//	tok4.next = &tok5;
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok2, tok));
	PASS();
}

SUITE (tok_pop)
{
//	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test_basic1);
}
