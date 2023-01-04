/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:28:55 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/18 17:08:33 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "libft.h"
#include "ft_isint.c"

#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <strings.h>

#define __STR(x) #x
#define STR(x) __STR(x)

TEST only_123(void)
{
	ASSERT(ft_isint("123"));

	PASS();
}

TEST leading_spaces_123(void)
{
	ASSERT(ft_isint("  123"));

	PASS();
}

TEST trailing_spaces_123(void)
{
	ASSERT(ft_isint("123   "));

	PASS();
}

TEST no_digits(void)
{
	ASSERT(ft_isint(" er"));

	PASS();
}

TEST empty(void)
{
	ASSERT(ft_isint(""));

	PASS();
}

TEST null(void)
{
	ASSERT_FALSE(ft_isint(NULL));

	PASS();
}

TEST max_int(void)
{
	char	nptr[] = STR(INT_MAX);

	ASSERT(ft_isint(nptr));

	PASS();
}

TEST min_int(void)
{
	char	nptr[] = STR(INT_MIN);

	ASSERT(ft_isint(nptr));

	PASS();
}

static void add_one(char *nptr)
{
	int			i;
	char const	len = strlen(nptr);
	char		*digit;

	i = 0;
	while (i < len)
	{
		digit = nptr + len - 1 - i;
		if (*digit < '9')
		{
			*digit += 1;
			if (i > 0)
				*(digit + 1) = '0';
			break;
		}
		i++;
	}
}

TEST add_one_helper(void)
{
	char	nptr[20];

	bzero(nptr, 20);
	strncpy(nptr, "123", 20);
	add_one(nptr);
	ASSERT_STR_EQm(nptr, nptr, "124");

	bzero(nptr, 20);
	strncpy(nptr, "129", 20);
	add_one(nptr);
	ASSERT_STR_EQm(nptr, nptr, "130");

	PASS();
}

TEST one_above_max_int(void)
{
	char	nptr[20];

	bzero(nptr, 20);
	snprintf(nptr, 20, "%i", INT_MAX);
	add_one(nptr);
	ASSERT_FALSEm(nptr, ft_isint(nptr));

	PASS();
}

TEST one_below_min_int(void)
{
	char	nptr[20];

	bzero(nptr, 20);
	snprintf(nptr, 20, "%i", INT_MIN);
	add_one(nptr);
	ASSERT_FALSEm(nptr, ft_isint(nptr));

	PASS();
}

SUITE (ft_isint_suite)
{
	RUN_TEST(only_123);
	RUN_TEST(leading_spaces_123);
	RUN_TEST(trailing_spaces_123);

	RUN_TEST(no_digits);
	RUN_TEST(empty);

	RUN_TEST(null);

	RUN_TEST(max_int);
	RUN_TEST(min_int);

	RUN_TEST(add_one_helper);
	RUN_TEST(one_above_max_int);
	RUN_TEST(one_below_min_int);
}
