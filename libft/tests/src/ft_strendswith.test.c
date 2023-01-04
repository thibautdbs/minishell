/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:10:12 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/09 16:17:24 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_strendswith.c"

TEST simple_tests()
{
	ASSERT(ft_strendswith("yo.ber", ".ber"));
	ASSERT(ft_strendswith(".ber", ".ber"));
	ASSERT_FALSE(ft_strendswith("ber", ".ber"));
	ASSERT_FALSE(ft_strendswith(".be", ".ber"));
	PASS();
}

SUITE (ft_strendswith_suite)
{
	RUN_TEST(simple_tests);
}
