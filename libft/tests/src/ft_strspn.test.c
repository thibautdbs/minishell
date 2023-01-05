/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:15:52 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/22 01:50:39 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "libft.h"
#include "ft_strspn.c"

TEST one_sep(void)
{
	ASSERT_EQ(ft_strspn("lol", " "), 0);
	ASSERT_EQ(ft_strspn(" lol", " "), 1);
	ASSERT_EQ(ft_strspn("  lol", " "), 2);
	ASSERT_EQ(ft_strspn("   lol", " "), 3);
	ASSERT_EQ(ft_strspn("", " "), 0);
	PASS();
}

TEST repeated_sep(void)
{
	ASSERT_EQ(ft_strspn("lol", "  "), 0);
	ASSERT_EQ(ft_strspn(" lol", "  "), 1);
	ASSERT_EQ(ft_strspn("  lol", "  "), 2);
	ASSERT_EQ(ft_strspn("   lol", "  "), 3);
	ASSERT_EQ(ft_strspn("", "  "), 0);
	PASS();
}

TEST two_seps(void)
{
	ASSERT_EQ(ft_strspn("alolb", "ab"), 1);
	ASSERT_EQ(ft_strspn("ablolb", "ab"), 2);
	ASSERT_EQ(ft_strspn("abalolb", "ab"), 3);
	ASSERT_EQ(ft_strspn("abalabalola", "ab"), 3);
	ASSERT_EQ(ft_strspn("", "ab"), 0);
	PASS();
}

SUITE (ft_strspn_suite)
{
	RUN_TEST(one_sep);
	RUN_TEST(repeated_sep);
	RUN_TEST(two_seps);
}
