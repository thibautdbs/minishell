/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 15:23:46 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "lexer/lex.c"
#include "minishell/lexer.h"
#include "minishell/parser.h"
#include "minishell/token.h"

////////////////////////////////////////////////////////////////////////////////
/// HELPERS

static	t_token	*mine;

static void	teardown(void *data)
{
	(void) data;
	my_tok_destroy(&mine);
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
	t_token	tok7 = {DOUBLEQUOTE, "\"", NULL};
	t_token	tok6 = {WORD, " ", &tok7};
	t_token	tok5 = {WORD, ")", &tok6};
	t_token	tok4 = {WORD, "oo", &tok5};
	t_token	tok3 = {WORD, "(", &tok4};
	t_token	tok2 = {WORD, " ", &tok3};
	t_token	tok1 = {DOUBLEQUOTE, "\"", &tok2};

	mine = my_lex("\" (oo) \"");
	t_success res = my_parse_quote(mine);
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	ASSERT_EQ(success, res);
	PASS();
}

TEST	test_simplequotes_in_doublequote()
{
	t_token	tok6 = {DOUBLEQUOTE, "\"", NULL};
	t_token	tok5 = {WORD, "\'", &tok6};
	t_token	tok4 = {WORD, "\'", &tok5};
	t_token	tok3 = {WORD, "\'", &tok4};
	t_token	tok2 = {WORD, "\'", &tok3};
	t_token	tok1 = {DOUBLEQUOTE, "\"", &tok2};

	mine = my_lex("\"\'\'\'\'\"");
	t_success res = my_parse_quote(mine);
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	ASSERT_EQ(success, res);
	PASS();
}

TEST	test_even_doublequotes_repetition()
{
	t_token	tok6 = {DOUBLEQUOTE, "\"", NULL};
	t_token	tok5 = {DOUBLEQUOTE, "\"", &tok6};
	t_token	tok4 = {DOUBLEQUOTE, "\"", &tok5};
	t_token	tok3 = {DOUBLEQUOTE, "\"", &tok4};
	t_token	tok2 = {DOUBLEQUOTE, "\"", &tok3};
	t_token	tok1 = {DOUBLEQUOTE, "\"", &tok2};

	mine = my_lex("\"\"\"\"\"\"");
	t_success res = my_parse_quote(mine);
	CHECK_CALL(ASSERT_TOKENS_MATCH(&tok1, mine));
	ASSERT_EQ(success, res);
	PASS();
}

TEST	test_odd_singlequotes_repetition()
{
	mine = my_lex("\'\'\'\'\'");
	t_success res = my_parse_quote(mine);
	ASSERT_EQ(failure, res);
	PASS();
}

SUITE (parse_quote)
{
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test_simplequotes_in_doublequote);
	RUN_TEST(test_even_doublequotes_repetition);
	RUN_TEST(test_odd_singlequotes_repetition);
	RUN_TEST(test_smiley_cochon);
}
