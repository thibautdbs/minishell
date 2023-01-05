/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:34:43 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/21 00:38:37 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_lstpush.c"
#include "libft.h"

#include <stddef.h> // NULL, size_t
#include <stdlib.h> // free
#include <string.h> //memcmp

typedef struct e_dummystruct
{
	int		a;
	char	b;
	char	*c;
}	t_dummystruct;

TEST	lst_size_should_be(t_list *lst, int size)
{
	ASSERT_EQ_FMT(size, ft_lstsize(lst), "%i");
	PASS();
}

TEST	lst_should_equal_array_of_int(t_list *lst, int *arr)
{
	int		ref;
	int		*content;
	size_t	i = 0;

	t_list	*node = lst;
	while (node != NULL)
	{
		ref = arr[i];
		content = node->content;
		ASSERT_EQ_FMT(ref, *content, "%i");
		ASSERT_MEM_EQ(&ref, content, sizeof(int));
		node = node->next;
		i++;
	}
	PASS();
}

TEST	lst_should_equal_array_of_char(t_list *lst, char *arr)
{
	char	ref;
	char	*content;
	size_t	i = 0;

	t_list	*node = lst;
	while (node != NULL)
	{
		ref = arr[i];
		content = node->content;
		ASSERT_EQ_FMT(ref, *content, "%c");
		ASSERT_MEM_EQ(&ref, content, sizeof(char));
		node = node->next;
		i++;
	}
	PASS();
}

TEST	lst_should_equal_array_of_array_of_int(t_list *lst, int arr[2][3])
{
	int		ref[3];
	int		*content;
	size_t	i = 0;

	t_list	*node = lst;
	while (node != NULL)
	{
		ft_memcpy(ref, arr[i], sizeof(ref));
		content = node->content;
		ASSERT_EQ(0, memcmp(ref, content, sizeof(ref)));
		ASSERT_MEM_EQ(ref, content, sizeof(ref));
		node = node->next;
		i++;
	}
	PASS();
}

TEST	lst_should_equal_array_of_struct(t_list *lst, t_dummystruct	*arr)
{
	t_dummystruct	ref;
	t_dummystruct	*content;
	size_t			i = 0;

	t_list	*node = lst;
	while (node != NULL)
	{
		ref = arr[i];
		content = node->content;
		ASSERT_EQ_FMT(ref.a, content->a, "%i");
		ASSERT_EQ_FMT(ref.b, content->b, "%c");
		ASSERT_EQ_FMT(ref.c, content->c, "%p");
		ASSERT_EQ(0, memcmp(&ref, content, sizeof(ref)));
		ASSERT_MEM_EQ(&ref, content, sizeof(ref));
		node = node->next;
		i++;
	}
	PASS();
}

SUITE (ft_lstpush_suite)
{
	int		arr1[6] = {0,1,2,3,4,5};
	t_list	*lst1 = ft_lstpush(arr1, 6, sizeof(int));
	greatest_set_test_suffix("6");
	RUN_TESTp(lst_size_should_be, lst1, 6);
	ft_lstclear(&lst1, free);

	int		arr2[1] = {123};
	t_list	*lst2 = ft_lstpush(arr2, 1, sizeof(int));
	greatest_set_test_suffix("1");
	RUN_TESTp(lst_size_should_be, lst2, 1);
	ft_lstclear(&lst2, free);

	int		arr3[2][3] = { {1,2,3}, {4,5,6} };
	t_list	*lst3 = ft_lstpush(arr3, 2, 3 * sizeof(int));
	greatest_set_test_suffix("2");
	RUN_TESTp(lst_size_should_be, lst3, 2);
	ft_lstclear(&lst3, free);

	int		nbrs[] = {1,2,12,3,123};
	t_list	*nbrslst = ft_lstpush(nbrs, sizeof(nbrs)/sizeof(int), sizeof(int));
	RUN_TESTp(lst_should_equal_array_of_int, nbrslst, nbrs);
	ft_lstclear(&nbrslst, free);

	char	str[] = "this is a test";
	t_list	*charlst = ft_lstpush(str, sizeof(str)/sizeof(char), sizeof(char));
	RUN_TESTp(lst_should_equal_array_of_char, charlst, str);
	ft_lstclear(&charlst, free);

	int		arr6[2][3] = { {1,256,42}, {75,24,6} };
	t_list	*lst6 = ft_lstpush(arr6, 2, 3 * sizeof(int));
	RUN_TESTp(lst_should_equal_array_of_array_of_int, lst6, arr6);
	ft_lstclear(&lst6, free);

	t_dummystruct	arr7[] = {
		{ .a = 42, .b = 'c', .c = (char*)46 },
		{ .a = 72, .b = 'z', .c = (char*)0 },
		{ .a = 0, .b = 'a', .c =(char*)1024 }
	};
	t_list	*lst7 = ft_lstpush(arr7, 3, sizeof(t_dummystruct));
	RUN_TESTp(lst_should_equal_array_of_struct, lst7, arr7);
	ft_lstclear(&lst7, free);
}
