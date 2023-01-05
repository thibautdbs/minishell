/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:12:52 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/19 20:46:25 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "libft.h"
#include "ft_lstindex.c"


TEST	get_index_from_null_list(void)
{
	ASSERT_EQ_FMT(-1, ft_lstindex(NULL, NULL, 0), "%i");
	PASS();
}

// #############
// ## int list #
// #############

TEST	get_first_index_from_list_of_int(t_list *lst)
{
	if (lst == NULL)
		SKIPm("malloc failed");
	ASSERT_EQ_FMT(0, ft_lstindex(lst, (int[1]){'a'}, sizeof(int)), "%i");
	PASS();
}

TEST	get_3rd_index_from_list_of_int(t_list *lst)
{
	if (lst == NULL)
		SKIPm("malloc failed");
	ASSERT_EQ_FMT(2, ft_lstindex(lst, (int[1]){'c'}, sizeof(int)), "%i");
	PASS();
}

TEST	get_last_index_from_list_of_int(t_list *lst)
{
	if (lst == NULL)
		SKIPm("malloc failed");
	ASSERT_EQ_FMT(4, ft_lstindex(lst, (int[1]){'e'}, sizeof(int)), "%i");
	PASS();
}

TEST	get_nonexisting_index_from_list_of_int(t_list *lst)
{
	if (lst == NULL)
		SKIPm("malloc failed");
	ASSERT_EQ_FMT(-1, ft_lstindex(lst, (int[1]){8}, sizeof(int)), "%i");
	PASS();
}

// ################
// ## string list #
// ################

TEST	get_first_index_from_list_of_strings(t_list *lst)
{
	if (lst == NULL)
		SKIPm("malloc failed");
	ASSERT_EQ_FMT(0, ft_lstindex(lst, "yo", sizeof("yo")), "%i");
	PASS();
}

TEST	get_3rd_index_from_list_of_strings(t_list *lst)
{
	if (lst == NULL)
		SKIPm("malloc failed");
	ASSERT_EQ_FMT(2, ft_lstindex(lst, "yoyoyo", sizeof("yoyoyo")), "%i");
	PASS();
}

TEST	get_last_index_from_list_of_strings(t_list *lst)
{
	if (lst == NULL)
		SKIPm("malloc failed");
	ASSERT_EQ_FMT(3, ft_lstindex(lst, "yoyoyoya", sizeof("yoyoyoya")), "%i");
	PASS();
}

TEST	get_nonexisting_index_from_list_of_strings(t_list *lst)
{
	if (lst == NULL)
		SKIPm("malloc failed");
	ASSERT_EQ_FMT(-1, ft_lstindex(lst, "wesh", sizeof("wesh")), "%i");
	PASS();
}

SUITE (ft_lstindex_suite)
{
	RUN_TEST(get_index_from_null_list);

	t_list	*lst = NULL;
	t_list	*node = NULL;
	int		nbrs[] = {'a','b','c','d','e'};
	for (size_t i = 0; i < sizeof(nbrs)/sizeof(int); i++)
	{
		node = ft_lstnew(nbrs + i);
		if (node == NULL)
		{
			ft_lstclear(&lst, NULL);
			break;
		}
		ft_lstadd_back(&lst, node);
	}
	RUN_TESTp(get_first_index_from_list_of_int, lst);
	RUN_TESTp(get_3rd_index_from_list_of_int, lst);
	RUN_TESTp(get_last_index_from_list_of_int, lst);
	RUN_TESTp(get_nonexisting_index_from_list_of_int, lst);
	ft_lstclear(&lst, NULL);

	lst = NULL;
	node = NULL;

	char *(strs[]) = {"yo", "yoyo", "yoyoyo", "yoyoyoya"};
	for (size_t i = 0; i < sizeof(strs)/sizeof(char*); i++)
	{
		node = ft_lstnew(strs[i]);
		if (node == NULL)
		{
			ft_lstclear(&lst, NULL);
			break;
		}
		ft_lstadd_back(&lst, node);
	}
	RUN_TESTp(get_first_index_from_list_of_strings, lst);
	RUN_TESTp(get_3rd_index_from_list_of_strings, lst);
	RUN_TESTp(get_last_index_from_list_of_strings, lst);
	RUN_TESTp(get_nonexisting_index_from_list_of_strings, lst);
	ft_lstclear(&lst, NULL);
}
