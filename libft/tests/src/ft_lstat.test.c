/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:56:00 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/22 18:44:51 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_lstat.c"
#include "libft.h"

#include <stdlib.h> // free

static t_list	*lst = NULL;

static void	setup(void *data)
{
	(void) data;
	int	arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	lst = ft_lstpush(arr, 9, sizeof(int));
}

static void	teardown(void *data)
{
	(void) data;
	ft_lstclear(&lst, free);
}

TEST	test_node(t_list *lst, int i, int ref)
{
	t_list *node = ft_lstat(lst, i);
	ASSERT_NEQ(NULL, node);
	ASSERT_NEQ(NULL, node->content);
	ASSERT_EQ_FMT(ref, *(int*)node->content, "%i");
	PASS();
}

TEST	positive_indexes(void)
{
	CHECK_CALL(test_node(lst, 0, 1));
	CHECK_CALL(test_node(lst, 1, 2));
	CHECK_CALL(test_node(lst, 2, 3));
	CHECK_CALL(test_node(lst, 3, 4));
	CHECK_CALL(test_node(lst, 4, 5));
	PASS();
}

TEST	negative_indexes(void)
{
	CHECK_CALL(test_node(lst, -1, 9));
	CHECK_CALL(test_node(lst, -2, 8));
	CHECK_CALL(test_node(lst, -3, 7));
	CHECK_CALL(test_node(lst, -4, 6));
	CHECK_CALL(test_node(lst, -5, 5));
	PASS();
}

TEST	wrong_index(void)
{
	ASSERT_EQ_FMT(NULL, ft_lstat(lst, 45), "%i");
	ASSERT_EQ_FMT(NULL, ft_lstat(lst, -45), "%i");
	ASSERT_EQ_FMT(NULL, ft_lstat(lst, 10), "%i");
	ASSERT_EQ_FMT(NULL, ft_lstat(lst, -10), "%i");
	PASS();
}

TEST null_lst(void)
{
	ASSERT_EQ(NULL, ft_lstat(NULL, 0));
	ASSERT_EQ(NULL, ft_lstat(NULL, -1));
	ASSERT_EQ(NULL, ft_lstat(NULL, 42));
	PASS();
}

SUITE (ft_lstat_suite)
{
	GREATEST_SET_SETUP_CB(setup, NULL);
	GREATEST_SET_TEARDOWN_CB(teardown, NULL);
	RUN_TEST(positive_indexes);
	RUN_TEST(negative_indexes);
	RUN_TEST(wrong_index);
	GREATEST_SET_SETUP_CB(NULL, NULL);
	GREATEST_SET_TEARDOWN_CB(NULL, NULL);
	RUN_TEST(null_lst);
}
