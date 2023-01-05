/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loc_skip_pars.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 21:18:39 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "lexer/lex.c"
#include "parser/parse.c"
#include "minishell/lexer.h"
#include "minishell/parser.h"
#include "minishell/token.h"

////////////////////////////////////////////////////////////////////////////////
/// HELPERS

static	int		i;
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
/*
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
*/
////////////////////////////////////////////////////////////////////////////////
/// TESTS

TEST	test_no_pars()
{
	t_token	tok6 = {DOUBLEQUOTE, "\"", NULL};
	t_token	tok5 = {DOUBLEQUOTE, "\"", &tok6};
	t_token	tok4 = {DOUBLEQUOTE, "\"", &tok5};
	t_token	tok3 = {DOUBLEQUOTE, "\"", &tok4};
	t_token	tok2 = {DOUBLEQUOTE, "\"", &tok3};
	t_token	tok1 = {DOUBLEQUOTE, "\"", &tok2};

	i = loc_skip_pars(&tok1);
	ASSERT_EQ_FMT(0, i, "%i");
	PASS();
}

SUITE (parse_quote)
{
//	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test_no_pars);
}
