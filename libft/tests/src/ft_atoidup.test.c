/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoidup.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:39:28 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/22 10:51:23 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_atoidup.c"
#include <stdlib.h>

TEST should_equal(int *n, int ref)
{
	ASSERT_NEQ(NULL, n);
	ASSERT_EQ_FMT(ref, *n, "%i");
	PASS();
}

SUITE (ft_atoidup_suite)
{
	greatest_set_test_suffix("123");
	int	*n1 = ft_atoidup("123");
	RUN_TESTp(should_equal, n1 , 123);
	ft_memdel((void*)&n1);

	greatest_set_test_suffix("1");
	int	*n2 = ft_atoidup("1");
	RUN_TESTp(should_equal, n2 , 1);
	ft_memdel((void*)&n2);

	greatest_set_test_suffix("0");
	int	*n3 = ft_atoidup("");
	RUN_TESTp(should_equal, n3 , 0);
	ft_memdel((void*)&n3);
}
