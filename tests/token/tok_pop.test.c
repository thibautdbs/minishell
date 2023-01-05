/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_pop.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 20:38:04 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "lexer/lex.c"
#include "minishell/lexer.h"
#include "minishell/token.h"

////////////////////////////////////////////////////////////////////////////////
/// HELPERS

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

TEST	test_pop_front_basic1()
{
	t_token	tok5 = {SPACES, " ", NULL};
	t_token	tok4 = {RIGHTPAR, ")", &tok5};
	t_token	tok3 = {WORD, "oo", &tok4};
	t_token	tok2 = {LEFTPAR, "(", &tok3};
	t_token	tok1 = {SPACES, " ", &tok2};

	t_token *tok;
	tok = &tok1;
	my_tok_pop_front(&tok);
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok2, tok));
	PASS();
}

TEST	test_pop_back_basic1()
{
	t_token	tok5 = {SPACES, " ", NULL};
	t_token	tok4 = {RIGHTPAR, ")", &tok5};
	t_token	tok3 = {WORD, "oo", &tok4};
	t_token	tok2 = {LEFTPAR, "(", &tok3};
	t_token	tok1 = {SPACES, " ", &tok2};

	t_token *tok;
	tok = &tok1;
	my_tok_pop_back(&tok);
	ASSERT_EQ_FMT(NULL, tok4.next, "%p");
	PASS();
}

SUITE (tok_pop)
{
	RUN_TEST(test_pop_front_basic1);
	RUN_TEST(test_pop_back_basic1);
}
