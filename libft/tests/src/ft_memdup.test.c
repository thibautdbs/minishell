/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:29:17 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/20 02:12:07 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_memdup.c"
#include "libft.h"

#include <stddef.h> // size_t

TEST should_return_null_when_buf_is_null(void)
{
	ASSERT_EQ(NULL, ft_memdup(NULL, 0));
	ASSERT_EQ(NULL, ft_memdup(NULL, 1));
	ASSERT_EQ(NULL, ft_memdup(NULL, 42));
	PASS();
}

TEST should_return_null_when_size_is_zero(void)
{
	ASSERT_EQ(NULL, ft_memdup("", 0));
	ASSERT_EQ(NULL, ft_memdup((int[2]){42,42}, 0));
	PASS();
}

TEST dup(void const *expected, void const *got, size_t size)
{
	ASSERT_MEM_EQ(expected, got, size);
	PASS();
}

SUITE (ft_memdup_suite)
{
	RUN_TEST(should_return_null_when_buf_is_null);
	RUN_TEST(should_return_null_when_size_is_zero);

	char const	str[] = "this is a test";
	char	*strdup = ft_memdup(str, sizeof(str)/sizeof(char));
	greatest_set_test_suffix("str");
	RUN_TESTp(dup, str, strdup, sizeof(str)/sizeof(char));
	ft_memdel((void*)&strdup);

	int const	nbrs[] = {1,2,3,4};
	int			*nbrsdup = ft_memdup(nbrs, sizeof(nbrs)/sizeof(int));
	greatest_set_test_suffix("int_array");
	RUN_TESTp(dup, nbrs, nbrsdup, sizeof(nbrs)/sizeof(int));
	ft_memdel((void*)&nbrsdup);

	struct
	{
		int		nb;
		char	c;
	} const	mystruct = { .nb = 123, .c = 't'};
	void	*mystructdup = ft_memdup(&mystruct, sizeof(mystruct));
	greatest_set_test_suffix("struct");
	RUN_TESTp(dup, &mystruct, mystructdup, sizeof(mystruct));
	ft_memdel((void*)&mystructdup);
}
