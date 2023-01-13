/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_word.test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:56:31 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/13 17:19:10 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"		//TEST LIB
#include "lexer/lex_word.c"	//TESTED FILE
#include "assertions/assert_toks_eq.c"

#include "minishell/lexer.h"
#include "minishell/toks.h"

////////////////////////////////////////////////////////////////////////////////
/// CLEANUP

static t_toks	*yours;

static void	teardown(void *data)
{
	(void) data;
	my_toks_del(&yours);
}

////////////////////////////////////////////////////////////////////////////////
/// TESTS

TEST	should_return_word_and_consume_all_str(void)
{
	t_toks	tok1 = {WORD, "word", NULL};

	char const		*str = "word";
	t_maybe_toks	res = my_lex_word(&str);
	ASSERT_EQ(NO_ERR, res.err);
	yours = res.toks;

	CHECK_CALL(ASSERT_TOKS_EQ(&tok1, yours));
	ASSERT_EQ(NULL, yours->next);
	ASSERT_STR_EQ("", str);
	PASS();
}

TEST	should_return_word_and_consume_only_word_from_str(void)
{
	t_toks	tok1 = {WORD, "word", NULL};

	char const		*str = "word lol";
	t_maybe_toks	res = my_lex_word(&str);
	ASSERT_EQ(NO_ERR, res.err);
	yours = res.toks;

	CHECK_CALL(ASSERT_TOKS_EQ(&tok1, yours));
	ASSERT_EQ(NULL, yours->next);
	ASSERT_STR_EQ(" lol", str);
	PASS();
}

SUITE(test_lex_word_fct)
{
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(should_return_word_and_consume_all_str);
	RUN_TEST(should_return_word_and_consume_only_word_from_str);
}
