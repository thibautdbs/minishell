/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/04 21:42:29 by ffeaugas         ###   ########.fr       */
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
	my_tok_destroy(mine);
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

TEST	test_smiley_cochon()
{
	t_token	tok7 = {WORD, "O", NULL};
	t_token	tok6 = {SPACES, " ", &tok7};
	t_token	tok5 = {RIGHTPAR, ")", &tok6};
	t_token	tok4 = {WORD, "oo", &tok5};
	t_token	tok3 = {LEFTPAR, "(", &tok4};
	t_token	tok2 = {SPACES, " ", &tok3};
	t_token	tok1 = {WORD, "O", &tok2};

	mine = my_lex("O (oo) O");
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	PASS();
}

TEST	test_two_distinct_alternate_token2()
{
	t_token	tok7 = {RIGHTPAR, ")", NULL};
	t_token	tok6 = {RIGHTPAR, ")", &tok7};
	t_token	tok5 = {LEFTAGBRACKET, "<", &tok6};
	t_token	tok4 = {RIGHTPAR, ")", &tok5};
	t_token	tok3 = {LEFTAGBRACKET, "<", &tok4};
	t_token	tok2 = {RIGHTPAR, ")", &tok3};
	t_token	tok1 = {LEFTAGBRACKET, "<", &tok2};

	mine = my_lex("<)<)<))");
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	PASS();
}

TEST	test_two_distinct_alternate_token()
{
	t_token	tok6 = {WORD, "333", NULL};
	t_token	tok5 = {SPACES, "   ", &tok6};
	t_token	tok4 = {WORD, "22", &tok5};
	t_token	tok3 = {SPACES, "  ", &tok4};
	t_token	tok2 = {WORD, "1", &tok3};
	t_token	tok1 = {SPACES, " ", &tok2};

	mine = my_lex(" 1  22   333");
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	PASS();
}

TEST	test_same_token_repetition()
{
	t_token	tok5 = {RIGHTPAR, ")", NULL};
	t_token	tok4 = {RIGHTPAR, ")", &tok5};
	t_token	tok3 = {RIGHTPAR, ")", &tok4};
	t_token	tok2 = {RIGHTPAR, ")", &tok3};
	t_token	tok1 = {RIGHTPAR, ")", &tok2};

	mine = my_lex(")))))");
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	PASS();
}

TEST	test_all_token_types()
{
	t_token	tok10 = {WORD, "ya5spacesjusteavant", NULL};
	t_token	tok9 = {SPACES, "     ", &tok10};
	t_token	tok8 = {RIGHTAGBRACKET, ">", &tok9};
	t_token	tok7 = {LEFTAGBRACKET, "<", &tok8};
	t_token	tok6 = {SINGLEQUOTE, "\'", &tok7};
	t_token	tok5 = {DOUBLEQUOTE, "\"", &tok6};
	t_token	tok4 = {RIGHTPAR, ")", &tok5};
	t_token	tok3 = {LEFTPAR, "(", &tok4};
	t_token	tok2 = {AND, "&", &tok3};
	t_token	tok1 = {PIPE, "|", &tok2};

	mine = my_lex("|&()\"\'<>     ya5spacesjusteavant");
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
