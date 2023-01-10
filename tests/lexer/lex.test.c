/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:29:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "lexer/lex.c"
#include "minishell/lexer.h"
#include "minishell/token.h"

////////////////////////////////////////////////////////////////////////////////
/// HELPERS

static	t_tok	*mine;

static void	teardown(void *data)
{
	(void) data;
	my_tok_destroy(&mine);
}

////////////////////////////////////////////////////////////////////////////////
/// ASSERTIONS

TEST ASSERT_TOKENS_MATCH(t_tok const *ref, t_tok const *mine)
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

TEST	test_smiley_cochon()
{
	t_tok	tok7 = {WORD, "O", NULL};
	t_tok	tok6 = {SPACES, " ", &tok7};
	t_tok	tok5 = {RIGHTPAR, ")", &tok6};
	t_tok	tok4 = {WORD, "oo", &tok5};
	t_tok	tok3 = {LEFTPAR, "(", &tok4};
	t_tok	tok2 = {SPACES, " ", &tok3};
	t_tok	tok1 = {WORD, "O", &tok2};

	mine = my_lex("O (oo) O");
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	PASS();
}

TEST	test_two_distinct_alternate_token2()
{
	t_tok	tok7 = {RIGHTPAR, ")", NULL};
	t_tok	tok6 = {RIGHTPAR, ")", &tok7};
	t_tok	tok5 = {LEFTAGBRACKET, "<", &tok6};
	t_tok	tok4 = {RIGHTPAR, ")", &tok5};
	t_tok	tok3 = {LEFTAGBRACKET, "<", &tok4};
	t_tok	tok2 = {RIGHTPAR, ")", &tok3};
	t_tok	tok1 = {LEFTAGBRACKET, "<", &tok2};

	mine = my_lex("<)<)<))");
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	PASS();
}

TEST	test_two_distinct_alternate_token()
{
	t_tok	tok6 = {WORD, "333", NULL};
	t_tok	tok5 = {SPACES, "   ", &tok6};
	t_tok	tok4 = {WORD, "22", &tok5};
	t_tok	tok3 = {SPACES, "  ", &tok4};
	t_tok	tok2 = {WORD, "1", &tok3};
	t_tok	tok1 = {SPACES, " ", &tok2};

	mine = my_lex(" 1  22   333");
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	PASS();
}

TEST	test_same_token_repetition()
{
	t_tok	tok5 = {RIGHTPAR, ")", NULL};
	t_tok	tok4 = {RIGHTPAR, ")", &tok5};
	t_tok	tok3 = {RIGHTPAR, ")", &tok4};
	t_tok	tok2 = {RIGHTPAR, ")", &tok3};
	t_tok	tok1 = {RIGHTPAR, ")", &tok2};

	mine = my_lex(")))))");
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	PASS();
}

TEST	test_all_token_types()
{
	t_tok	tok12 = {WORD, "ya5spacesjusteavant", NULL};
	t_tok	tok11 = {SPACES, "     ", &tok12};
	t_tok	tok10 = {QMARK, "?", &tok11};
	t_tok	tok9 = {DOLLAR, "$", &tok10};
	t_tok	tok8 = {RIGHTAGBRACKET, ">", &tok9};
	t_tok	tok7 = {LEFTAGBRACKET, "<", &tok8};
	t_tok	tok6 = {SINGLEQUOTE, "\'", &tok7};
	t_tok	tok5 = {DOUBLEQUOTE, "\"", &tok6};
	t_tok	tok4 = {RIGHTPAR, ")", &tok5};
	t_tok	tok3 = {LEFTPAR, "(", &tok4};
	t_tok	tok2 = {AND, "&", &tok3};
	t_tok	tok1 = {PIPE, "|", &tok2};

	mine = my_lex("|&()\"\'<>$?     ya5spacesjusteavant");
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	PASS();
}

SUITE (lex)
{
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test_all_token_types);
	RUN_TEST(test_same_token_repetition);
	RUN_TEST(test_two_distinct_alternate_token);
	RUN_TEST(test_two_distinct_alternate_token2);
	RUN_TEST(test_smiley_cochon);
}
