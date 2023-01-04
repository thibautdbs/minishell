/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:22:00 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/23 00:01:09 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_lstpop.c"
#include "libft.h"

#include <strings.h>

#define LSTSIZE 5

static t_list	*lst;
static t_list	*node[LSTSIZE];

static void	setup_5item_lst(void *data)
{
	(void) data;
	lst = NULL;
	bzero(node, sizeof(node));

	int arr[] = { 1, 2, 3, 4, 5 };
	lst	= ft_lstpush(arr, 5, sizeof(int));
}

void	setup_1item_lst(void *data)
{
	(void) data;
	bzero(node, sizeof(node));

	int	arr[] = { 42 };
	lst = ft_lstpush(arr, 1, sizeof(int));
}

static void	teardown(void *data)
{
	(void) data;
	ft_lstclear(&lst, free);
	for (int i = 0; i < LSTSIZE; i++)
	{
		ft_lstclear(&node[i], free);
	}
}

TEST	test_node(t_list *lst, int i, int ref)
{
	t_list	*node = ft_lstat(lst, i);
	ASSERT_NEQ(NULL, node);
	ASSERT_NEQ(NULL, node->content);
	ASSERT_EQ_FMT(ref, *(int*)node->content, "%i");
	PASS();
}

TEST	should_pop_last(void)
{
	node[0] = ft_lstpop(&lst, -1);

	CHECK_CALL(test_node(node[0], 0, 5));
	ASSERT_EQ(NULL, node[0]->next);

	CHECK_CALL(test_node(lst, 0, 1));
	CHECK_CALL(test_node(lst, 1, 2));
	CHECK_CALL(test_node(lst, 2, 3));
	CHECK_CALL(test_node(lst, 3, 4));
	ASSERT_EQ(NULL, ft_lstat(lst, 3)->next);

	ASSERT_EQ(NULL, ft_lstat(lst, 4));
	ASSERT_EQ(4, ft_lstsize(lst));

	PASS();
}

TEST	should_pop_2lasts(void)
{
	node[0] = ft_lstpop(&lst, -1);
	node[1] = ft_lstpop(&lst, -1);
	
	CHECK_CALL(test_node(node[0], 0, 5));
	ASSERT_EQ(NULL, node[0]->next);
	CHECK_CALL(test_node(node[1], 0, 4));
	ASSERT_EQ(NULL, node[1]->next);

	CHECK_CALL(test_node(lst, 0, 1));
	CHECK_CALL(test_node(lst, 1, 2));
	CHECK_CALL(test_node(lst, 2, 3));
	ASSERT_EQ(NULL, ft_lstat(lst, 2)->next);

	ASSERT_EQ(NULL, ft_lstat(lst, 3));
	ASSERT_EQ(3, ft_lstsize(lst));

	PASS();
}

TEST wrong_index(void)
{
	ASSERT_EQ(NULL, ft_lstpop(&lst, 10));
	ASSERT_EQ(NULL, ft_lstpop(&lst, -10));
	ASSERT_EQ(NULL, ft_lstpop(&lst, 100));
	ASSERT_EQ(NULL, ft_lstpop(&lst, -100));
	PASS();
}

TEST should_pop_1st(void)
{
	node[0] = ft_lstpop(&lst, 0);

	CHECK_CALL(test_node(node[0], 0, 1));
	ASSERT_EQ(NULL, node[0]->next);

	CHECK_CALL(test_node(lst, 0, 2));
	CHECK_CALL(test_node(lst, 1, 3));
	CHECK_CALL(test_node(lst, 2, 4));
	CHECK_CALL(test_node(lst, 3, 5));
	ASSERT_EQ(NULL, ft_lstat(lst, 3)->next);

	ASSERT_EQ(NULL, ft_lstat(lst, 4));
	ASSERT_EQ(4, ft_lstsize(lst));

	PASS();
}

TEST should_pop_1st_n_2nd(void)
{
	node[0] = ft_lstpop(&lst, 0);
	node[1] = ft_lstpop(&lst, 0);

	CHECK_CALL(test_node(node[0], 0, 1));
	ASSERT_EQ(NULL, node[0]->next);
	CHECK_CALL(test_node(node[1], 0, 2));
	ASSERT_EQ(NULL, node[1]->next);

	CHECK_CALL(test_node(lst, 0, 3));
	CHECK_CALL(test_node(lst, 1, 4));
	CHECK_CALL(test_node(lst, 2, 5));
	ASSERT_EQ(NULL, ft_lstat(lst, 2)->next);

	ASSERT_EQ(NULL, ft_lstat(lst, 3));
	ASSERT_EQ(3, ft_lstsize(lst));

	PASS();
}

TEST should_pop_2nd(void)
{
	node[0] = ft_lstpop(&lst, 1);

	CHECK_CALL(test_node(node[0], 0, 2));
	ASSERT_EQ(NULL, node[0]->next);

	CHECK_CALL(test_node(lst, 0, 1));
	CHECK_CALL(test_node(lst, 1, 3));
	CHECK_CALL(test_node(lst, 2, 4));
	CHECK_CALL(test_node(lst, 3, 5));
	ASSERT_EQ(NULL, ft_lstat(lst, 3)->next);

	ASSERT_EQ(NULL, ft_lstat(lst, 4));
	ASSERT_EQ(4, ft_lstsize(lst));

	PASS();
}

TEST should_pop_2nd_n_3rd(void)
{
	node[0] = ft_lstpop(&lst, 1);
	node[1] = ft_lstpop(&lst, 1);

	CHECK_CALL(test_node(node[0], 0, 2));
	ASSERT_EQ(NULL, node[0]->next);
	CHECK_CALL(test_node(node[1], 0, 3));
	ASSERT_EQ(NULL, node[1]->next);

	CHECK_CALL(test_node(lst, 0, 1));
	CHECK_CALL(test_node(lst, 1, 4));
	CHECK_CALL(test_node(lst, 2, 5));
	ASSERT_EQ(NULL, ft_lstat(lst, 2)->next);

	ASSERT_EQ(NULL, ft_lstat(lst, 3));
	ASSERT_EQ(3, ft_lstsize(lst));

	PASS();
}

TEST should_pop_1st_item_from_lst_of_1_item(void)
{
	node[0] = ft_lstpop(&lst, 0);


	CHECK_CALL(test_node(node[0], 0, 42));
	ASSERT_EQ(NULL, node[0]->next);

	ASSERT_EQ(NULL, lst);
	PASS();
}

TEST should_pop_last_item_from_lst_of_1_item(void)
{
	node[0] = ft_lstpop(&lst, -1);


	CHECK_CALL(test_node(node[0], 0, 42));
	ASSERT_EQ(NULL, node[0]->next);

	ASSERT_EQ(NULL, lst);
	PASS();
}

TEST	pop_1_item_from_empty_lst_should_return_null(void)
{
	ASSERT_EQ(NULL, ft_lstpop(NULL, 0));
	ASSERT_EQ(NULL, ft_lstpop(NULL, 42));
	ASSERT_EQ(NULL, ft_lstpop(NULL, -42));
	lst = NULL;
	ASSERT_EQ(NULL, ft_lstpop(&lst, 0));
	ASSERT_EQ(NULL, ft_lstpop(&lst, 42));
	ASSERT_EQ(NULL, ft_lstpop(&lst, -42));
	PASS();
}

SUITE (ft_lstpop_suite)
{
	RUN_TEST(pop_1_item_from_empty_lst_should_return_null);

	SET_SETUP(setup_5item_lst, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(wrong_index);
	RUN_TEST(should_pop_last);
	RUN_TEST(should_pop_2lasts);
	RUN_TEST(should_pop_1st);
	RUN_TEST(should_pop_1st_n_2nd);
	RUN_TEST(should_pop_2nd);
	RUN_TEST(should_pop_2nd_n_3rd);

	SET_SETUP(setup_1item_lst, NULL);
	RUN_TEST(should_pop_1st_item_from_lst_of_1_item);
	RUN_TEST(should_pop_last_item_from_lst_of_1_item);
}
