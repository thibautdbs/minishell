/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loc_skip_pars.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:53 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/06 09:11:14 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "parser/parse_split.c"

#include "minishell/lexer.h"
#include "minishell/parser.h"
#include "minishell/token.h"

////////////////////////////////////////////////////////////////////////////////
/// TESTS

TEST	test_1deep()
{
	t_token	tok6 = {RIGHTPAR, ")", NULL};
	t_token	tok5 = {DOUBLEQUOTE, "\"", &tok6};
	t_token	tok4 = {DOUBLEQUOTE, "\"", &tok5};
	t_token	tok3 = {DOUBLEQUOTE, "\"", &tok4};
	t_token	tok2 = {DOUBLEQUOTE, "\"", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};

	ASSERT_EQ_FMT(6, loc_skip_pars(&tok1), "%i");
	PASS();
}

TEST	test_1deep_trailing()
{
	t_token	tok6 = {DOUBLEQUOTE, "\"", NULL};
	t_token	tok5 = {DOUBLEQUOTE, "\"", &tok6};
	t_token	tok4 = {DOUBLEQUOTE, "\"", &tok5};
	t_token	tok3 = {RIGHTPAR, ")", &tok4};
	t_token	tok2 = {DOUBLEQUOTE, "\"", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};

	ASSERT_EQ_FMT(3, loc_skip_pars(&tok1), "%i");
	PASS();
}

TEST	test_2deep()
{
	t_token	tok6 = {RIGHTPAR, ")", NULL};
	t_token	tok5 = {RIGHTPAR, ")", &tok6};
	t_token	tok4 = {DOUBLEQUOTE, "\"", &tok5};
	t_token	tok3 = {DOUBLEQUOTE, "\"", &tok4};
	t_token	tok2 = {LEFTPAR, "(", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};

	ASSERT_EQ_FMT(6, loc_skip_pars(&tok1), "%i");
	PASS();
}

TEST	test_2deep2()
{
	t_token	tok6 = {RIGHTPAR, ")", NULL};
	t_token	tok5 = {DOUBLEQUOTE, "\"", &tok6};
	t_token	tok4 = {RIGHTPAR, ")", &tok5};
	t_token	tok3 = {LEFTPAR, "(", &tok4};
	t_token	tok2 = {DOUBLEQUOTE, "\"", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};

	ASSERT_EQ_FMT(6, loc_skip_pars(&tok1), "%i");
	PASS();
}

TEST	test_asym_1deep()
{
	t_token	tok6 = {DOUBLEQUOTE, "\"", NULL};
	t_token	tok5 = {DOUBLEQUOTE, "\"", &tok6};
	t_token	tok4 = {DOUBLEQUOTE, "\"", &tok5};
	t_token	tok3 = {DOUBLEQUOTE, "\"", &tok4};
	t_token	tok2 = {DOUBLEQUOTE, "\"", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};

	ASSERT_EQ_FMT(6, loc_skip_pars(&tok1), "%i");
	PASS();
}

TEST	test_asym_2deep()
{
	t_token	tok6 = {DOUBLEQUOTE, "\"", NULL};
	t_token	tok5 = {RIGHTPAR, ")", &tok6};
	t_token	tok4 = {DOUBLEQUOTE, "\"", &tok5};
	t_token	tok3 = {DOUBLEQUOTE, "\"", &tok4};
	t_token	tok2 = {LEFTPAR, "(", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};

	ASSERT_EQ_FMT(6, loc_skip_pars(&tok1), "%i");
	PASS();
}

TEST	test_asym_2deep2()
{
	t_token	tok6 = {DOUBLEQUOTE, "\"", NULL};
	t_token	tok5 = {RIGHTPAR, ")", &tok6};
	t_token	tok4 = {DOUBLEQUOTE, "\"", &tok5};
	t_token	tok3 = {LEFTPAR, "(", &tok4};
	t_token	tok2 = {DOUBLEQUOTE, "\"", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};

	ASSERT_EQ_FMT(6, loc_skip_pars(&tok1), "%i");
	PASS();
}

SUITE (test_loc_skip_pars)
{
	RUN_TEST(test_1deep);
	RUN_TEST(test_1deep_trailing);
	RUN_TEST(test_2deep);
	RUN_TEST(test_2deep2);
	RUN_TEST(test_asym_1deep);
	RUN_TEST(test_asym_2deep);
	RUN_TEST(test_asym_2deep2);
}
