/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:44:07 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/13 16:57:11 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"	//TEST LIB
#include "lexer/lex.c"	//TESTED FILE
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

TEST	should_return_WORD_BLANKS_WORD_BLANKS_WORD(void)
{
	t_toks	tok5 = {WORD, "cmd3", NULL};
	t_toks	tok4 = {BLANKS, " ", &tok5};
	t_toks	tok3 = {WORD, "cmd2", &tok4};
	t_toks	tok2 = {BLANKS, " ", &tok3};
	t_toks	tok1 = {WORD, "cmd1", &tok2};

	t_maybe_toks res = my_lex("cmd1 cmd2 cmd3");

	ASSERT_EQ(NO_ERR, res.err);
	yours = res.toks;
	CHECK_CALL(ASSERT_TOKS_EQ(&tok1, yours));
	PASS();
}

SUITE(test_lex_fct)
{
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(should_return_WORD_BLANKS_WORD_BLANKS_WORD);
}
