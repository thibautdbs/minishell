/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:25:02 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/06 15:06:36 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "parser/parse_split.c"

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/token.h"
#include "minishell/parser.h"
#include "debug.h"

static	t_cmd	*mine;

static void	teardown(void *data)
{
	(void)data;
	my_cmd_destroy(&mine);
}

////////////////////////////////////////////////////////////////////////////////
/// MOCKS

t_cmd	*my_parse(t_token *toks)
{
	t_cmd	*cmd = ft_calloc(1, sizeof(t_cmd));

	cmd->type = CMD_EXEC;
	cmd->left = NULL;
	cmd->right = NULL;
	int const size = my_tok_size(toks);
	cmd->args = ft_calloc(size + 1, sizeof(char*));
	for (int i = 0; i < size; i++)
		cmd->args[i] = ft_strdup(my_tok_at(toks, i)->content);
	cmd->args[size] = NULL;
	return (cmd);
}

////////////////////////////////////////////////////////////////////////////////
/// ASSERTIONS

TEST ASSERT_t_cmd_match(t_cmd *ref, t_cmd *mine)
{
	ASSERT_NEQ(NULL, ref);
	ASSERT_NEQ(NULL, mine);
	ASSERT_EQ(ref->type, mine->type);

	if (ref->type == CMD_EXEC)
	{
		for (int i = 0; ref->args[i] != NULL; i++)
			ASSERT_STR_EQ(ref->args[i], mine->args[i]);
	}
	if (ref->type != CMD_EXEC)
	{
		ASSERT_NEQ(NULL, ref->left);
		ASSERT_NEQ(NULL, mine->left);
		CHECK_CALL(ASSERT_t_cmd_match(ref->left, mine->left));

		ASSERT_NEQ(NULL, ref->right);
		ASSERT_NEQ(NULL, mine->right);
		CHECK_CALL(ASSERT_t_cmd_match(ref->right, mine->right));
	}
	PASS();
}

////////////////////////////////////////////////////////////////////////////////
/// TEST

/// 1deep_nopars

TEST test_pipe_1deep_nopars()
{
	t_token	tok7 = {WORD, "f", NULL};
	t_token	tok6 = {WORD, "e", &tok7};
	t_token	tok5 = {WORD, "d", &tok6};
	t_token	tok4 = {PIPE, "|", &tok5};
	t_token	tok3 = {WORD, "c", &tok4};
	t_token	tok2 = {WORD, "b", &tok3};
	t_token	tok1 = {WORD, "a", &tok2};

		t_cmd	cmd3 = {CMD_EXEC, NULL, NULL, (char*[]){"d", "e", "f", NULL}};
		t_cmd	cmd2 = {CMD_EXEC, NULL, NULL, (char*[]){"a", "b", "c", NULL}};
	t_cmd	cmd1 = {CMD_PIPE, &cmd2, &cmd3, NULL};

	mine = my_parse_split(&tok1);
	CHECK_CALL(ASSERT_t_cmd_match(&cmd1, mine));
	PASS();
}

TEST test_or_1deep_nopars()
{
	t_token	tok7 = {WORD, "e", NULL};
	t_token	tok6 = {WORD, "d", &tok7};
	t_token	tok5 = {PIPE, "|", &tok6};
	t_token	tok4 = {PIPE, "|", &tok5};
	t_token	tok3 = {WORD, "c", &tok4};
	t_token	tok2 = {WORD, "b", &tok3};
	t_token	tok1 = {WORD, "a", &tok2};

		t_cmd	cmd3 = {CMD_EXEC, NULL, NULL, (char*[]){"d", "e", NULL}};
		t_cmd	cmd2 = {CMD_EXEC, NULL, NULL, (char*[]){"a", "b", "c", NULL}};
	t_cmd	cmd1 = {CMD_OR, &cmd2, &cmd3, NULL};

	mine = my_parse_split(&tok1);
	CHECK_CALL(ASSERT_t_cmd_match(&cmd1, mine));
	PASS();
}

TEST test_and_1deep_nopars()
{
	t_token	tok7 = {WORD, "e", NULL};
	t_token	tok6 = {WORD, "d", &tok7};
	t_token	tok5 = {AND, "&", &tok6};
	t_token	tok4 = {AND, "&", &tok5};
	t_token	tok3 = {WORD, "c", &tok4};
	t_token	tok2 = {WORD, "b", &tok3};
	t_token	tok1 = {WORD, "a", &tok2};

		t_cmd	cmd3 = {CMD_EXEC, NULL, NULL, (char*[]){"d", "e", NULL}};
		t_cmd	cmd2 = {CMD_EXEC, NULL, NULL, (char*[]){"a", "b", "c", NULL}};
	t_cmd	cmd1 = {CMD_AND, &cmd2, &cmd3, NULL};

	mine = my_parse_split(&tok1);
	CHECK_CALL(ASSERT_t_cmd_match(&cmd1, mine));
	PASS();
}

/// 1deep_pars

TEST test_pipe_1deep_pars()
{
	t_token	tok7 = {WORD, "f", NULL};
	t_token	tok6 = {WORD, "e", &tok7};
	t_token	tok5 = {WORD, "d", &tok6};
	t_token	tok4 = {PIPE, "|", &tok5};
	t_token	tok3 = {RIGHTPAR, ")", &tok4};
	t_token	tok2 = {PIPE, "|", &tok3};
	t_token	tok1 = {LEFTPAR, "(", &tok2};

		t_cmd	cmd3 = {CMD_EXEC, NULL, NULL, (char*[]){"d", "e", "f", NULL}};
		t_cmd	cmd2 = {CMD_EXEC, NULL, NULL, (char*[]){"(", "|", ")", NULL}};
	t_cmd	cmd1 = {CMD_PIPE, &cmd2, &cmd3, NULL};

	mine = my_parse_split(&tok1);
	CHECK_CALL(ASSERT_t_cmd_match(&cmd1, mine));
	PASS();
}

TEST test_pipe_1deep_pars_right()
{
	t_token	tok7 = {RIGHTPAR, ")", NULL};
	t_token	tok6 = {PIPE, "|", &tok7};
	t_token	tok5 = {LEFTPAR, "(", &tok6};
	t_token	tok4 = {PIPE, "|", &tok5};
	t_token	tok3 = {WORD, "c", &tok4};
	t_token	tok2 = {WORD, "b", &tok3};
	t_token	tok1 = {WORD, "a", &tok2};

		t_cmd	cmd3 = {CMD_EXEC, NULL, NULL, (char*[]){"(", "|", ")", NULL}};
		t_cmd	cmd2 = {CMD_EXEC, NULL, NULL, (char*[]){"a", "b", "c", NULL}};
	t_cmd	cmd1 = {CMD_PIPE, &cmd2, &cmd3, NULL};

	mine = my_parse_split(&tok1);
	CHECK_CALL(ASSERT_t_cmd_match(&cmd1, mine));
	PASS();
}

// 2deep_nopars

TEST test_pipe_2deep_nopars()
{
	t_token	tok7 = {WORD, "f", NULL};
	t_token	tok6 = {PIPE, "|", &tok7};
	t_token	tok5 = {WORD, "d", &tok6};
	t_token	tok4 = {PIPE, "|", &tok5};
	t_token	tok3 = {WORD, "c", &tok4};
	t_token	tok2 = {WORD, "b", &tok3};
	t_token	tok1 = {WORD, "a", &tok2};

		t_cmd	cmd3 = {CMD_EXEC, NULL, NULL, (char*[]){"d", "|", "f", NULL}};
		t_cmd	cmd2 = {CMD_EXEC, NULL, NULL, (char*[]){"a", "b", "c", NULL}};
	t_cmd	cmd1 = {CMD_PIPE, &cmd2, &cmd3, NULL};

	mine = my_parse_split(&tok1);
	CHECK_CALL(ASSERT_t_cmd_match(&cmd1, mine));
	PASS();
}

SUITE (test_parse_split_fct)
{
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test_pipe_1deep_nopars);
	RUN_TEST(test_or_1deep_nopars);
	RUN_TEST(test_and_1deep_nopars);

	RUN_TEST(test_pipe_1deep_pars);
	RUN_TEST(test_pipe_1deep_pars_right);

	RUN_TEST(test_pipe_2deep_nopars);
}
