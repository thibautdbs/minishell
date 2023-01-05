/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstload.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:51:06 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/24 14:47:19 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_lstload.c"

#include <stddef.h>
#include <string.h>

#include "libft.h"

static t_list	*lst;

void	setup(void *data)
{
	(void) data;
	lst = NULL;
}

void	teardown(void *data)
{
	(void) data;
	ft_lstclear(&lst, NULL);
}

TEST	test_int_node(t_list *lst, int i, int ref)
{
	t_list	*node = ft_lstat(lst, i);
	ASSERT_NEQ(NULL, node);
	ASSERT_NEQ(NULL, node->content);
	ASSERT_EQ_FMT(ref, *(int*)node->content, "%i");
	PASS();
}

TEST	test_str_node(t_list *lst, int i, char const *ref)
{
	t_list	*node = ft_lstat(lst, i);
	ASSERT_NEQ(NULL, node);
	ASSERT_NEQ(NULL, node->content);
	ASSERT_STR_EQ(ref, node->content);
	PASS();
}

TEST should_load_3_int_nodes(void)
{
	int a = 1;
	int b = 2;
	int c = 3;
	int *nbrs[] = {&a,&b,&c};
	lst = ft_lstload(nbrs, 3);
	CHECK_CALL(test_int_node(lst, 0, 1));
	CHECK_CALL(test_int_node(lst, 1, 2));
	CHECK_CALL(test_int_node(lst, 2, 3));
	ASSERT_EQ(NULL, ft_lstat(lst, 3));
	ASSERT_EQ_FMT(3, ft_lstsize(lst), "%i");
	PASS();
}

TEST should_load_3_strings(void)
{
	char	*strs[3] = { "yoyo", "yaya", "tototest"};
	lst = ft_lstload(strs, 3);
	CHECK_CALL(test_str_node(lst, 0, "yoyo"));
	CHECK_CALL(test_str_node(lst, 1, "yaya"));
	CHECK_CALL(test_str_node(lst, 2, "tototest"));
	ASSERT_EQ(NULL, ft_lstat(lst, 3));
	ASSERT_EQ_FMT(3, ft_lstsize(lst), "%i");
	PASS();
}

TEST should_return_null_after_loading_null_array()
{
	ASSERT_EQ(NULL, ft_lstload(NULL, 0));
	ASSERT_EQ(NULL, ft_lstload(NULL, 42));
	ASSERT_EQ(NULL, ft_lstload(NULL, -42));
	PASS();
}

TEST should_return_null_after_loading_empty_array()
{
	char	*strs[] = {};
	int		*nbrs[] = {};
	ASSERT_EQ(NULL, ft_lstload(strs, 0));
	ASSERT_EQ(NULL, ft_lstload(nbrs, 0));
	PASS();
}

SUITE (ft_lstload_suite)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(should_load_3_int_nodes);
	RUN_TEST(should_load_3_strings);
	RUN_TEST(should_return_null_after_loading_null_array);
	RUN_TEST(should_return_null_after_loading_empty_array);
}
