/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:28:46 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/24 15:51:40 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_indexof.c"

#include <stddef.h>
#include <string.h>

#include "libft.h"

TEST should_return_1st_node_of_ints()
{
	int	nbrs[] = {1,2,3,4};
	ASSERT_EQ_FMT(0, ft_indexof(nbrs, (int[]){1}, 4, sizeof(int)), "%i");
	PASS();
}

TEST should_return_last_node_of_ints()
{
	int	nbrs[] = {1,2,3,4};
	ASSERT_EQ_FMT(3, ft_indexof(nbrs, (int[]){4}, 4, sizeof(int)), "%i");
	PASS();
}

TEST should_return_1st_node_of_strs()
{
	char	nbrs[][3] = {"123", "456","789", "785"};
	ASSERT_EQ_FMT(0, ft_indexof(nbrs, (char*)"123", 4, sizeof(char[3])), "%i");
	PASS();
}

TEST should_return_last_node_of_strs()
{
	char	nbrs[][3] = {"123", "456","789", "785"};
	ASSERT_EQ_FMT(3, ft_indexof(nbrs, (char*)"785", 4, sizeof(char[3])), "%i");
	PASS();
}

TEST should_return_minus1_if_ref_mot_found()
{
	int	nbrs[] = {1,2,3,4};
	ASSERT_EQ_FMT(-1, ft_indexof(nbrs, (int[]){42}, 4, sizeof(int)), "%i");
	PASS();
}

TEST should_return_minus1_if_arr_is_null()
{
	ASSERT_EQ_FMT(-1, ft_indexof(NULL, (int[]){42}, 4, sizeof(int)), "%i");
	PASS();
}

TEST should_return_minus1_if_ref_is_null()
{
	int	nbrs[] = {1,2,3,4};
	ASSERT_EQ_FMT(-1, ft_indexof(nbrs, NULL, 4, sizeof(int)), "%i");
	PASS();
}

SUITE (ft_index_of_suite)
{
	RUN_TEST(should_return_1st_node_of_ints);
	RUN_TEST(should_return_last_node_of_ints);
	RUN_TEST(should_return_1st_node_of_strs);
	RUN_TEST(should_return_last_node_of_strs);
	RUN_TEST(should_return_minus1_if_ref_mot_found);
	RUN_TEST(should_return_minus1_if_arr_is_null);
	RUN_TEST(should_return_minus1_if_ref_is_null);
}
