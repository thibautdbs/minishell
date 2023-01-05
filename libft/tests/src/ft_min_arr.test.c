/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_arr.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:28:07 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/23 18:43:34 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_min_arr.c"

#include "libft.h"

TEST positive_increasing_seq(void)
{
	ASSERT_EQ_FMT(1, ft_min_arr((int[]){1,2,3,4,5}, 5), "%i");
	PASS();
}

TEST positive_decreasing_seq(void)
{
	ASSERT_EQ_FMT(1, ft_min_arr((int[]){5,4,3,2,1}, 5), "%i");
	PASS();
}

TEST positive_arbitrary_seq(void)
{
	ASSERT_EQ_FMT(3, ft_min_arr((int[]){42,9,3,4,5}, 5), "%i");
	PASS();
}

TEST negative_increasing_seq(void)
{
	ASSERT_EQ_FMT(-42, ft_min_arr((int[]){-42,-9,-3,-2,-1}, 5), "%i");
	PASS();
}

TEST null_seq(void)
{
	ASSERT_EQ(0, ft_min_arr(NULL, 0));
	ASSERT_EQ(0, ft_min_arr(NULL, 42));
	ASSERT_EQ(0, ft_min_arr(NULL, -42));
	PASS();
}

TEST null_size(void)
{
	ASSERT_EQ(0, ft_min_arr((int[]){1,2,3,4,5}, 0));
	PASS();
}

SUITE (ft_min_arr_suite)
{
	RUN_TEST(positive_arbitrary_seq);
	RUN_TEST(positive_increasing_seq);
	RUN_TEST(positive_decreasing_seq);
	RUN_TEST(negative_increasing_seq);
	RUN_TEST(null_seq);
	RUN_TEST(null_size);
}
