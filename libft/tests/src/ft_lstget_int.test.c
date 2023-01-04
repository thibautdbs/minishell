/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_int.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:42:28 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/24 18:46:40 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_lstget_int.c"

#include "libft.h"

TEST basic_assertion(void)
{
	int i = 42;
	t_list node = {.content = &i, .next = NULL};
	ASSERT_EQ(42, ft_lstget_int(&node));
	PASS();
}

SUITE (ft_lstget_int_suite)
{
	RUN_TEST(basic_assertion);
}
