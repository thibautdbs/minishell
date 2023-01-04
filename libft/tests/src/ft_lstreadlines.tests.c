/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadlines.tests.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:49:10 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/12 09:32:25 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_lstreadlines.c"
#include "libft.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int 		fd;
static char		filename[11];
static t_list	*lst;

static void setup(void *data)
{
	(void) data;
	lst = NULL;
	strncpy(filename, "FT_XXXXXXX", 11);
	fd = mkstemp(filename);

	write(fd, "line1\n", 6);
	write(fd, "line2\n", 6);
	write(fd, "line3\n", 6);
	write(fd, "\n", 1);
	write(fd, "line5\n", 6);
	lseek(fd, 0, SEEK_SET);
}

static void teardown(void *data)
{
	(void) data;
	close(fd);
	unlink(filename);
	ft_lstclear(&lst, free);
}

TEST basic_1(void)
{
	lst = ft_lstreadlines(fd);
	ASSERT_STR_EQ(ft_lstat(lst, 0)->content, "line1\n");
	ASSERT_STR_EQ(ft_lstat(lst, 1)->content, "line2\n");
	ASSERT_STR_EQ(ft_lstat(lst, 2)->content, "line3\n");
	ASSERT_STR_EQ(ft_lstat(lst, 3)->content, "\n");
	ASSERT_STR_EQ(ft_lstat(lst, 4)->content, "line5\n");
	PASS();
}

SUITE(ft_lstreadlines_suite)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(basic_1);
}
