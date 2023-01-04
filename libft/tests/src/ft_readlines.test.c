/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlines.test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:23:25 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/12 13:54:59 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "ft_readlines.c"

#include "unistd.h"

static int 		fd;
static char		filename[11];
static char		**lines;

static void setup(void *data)
{
	(void) data;
	lines = NULL;
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
	if (lines != NULL)
	{
		for (int i = 0; lines[i] != NULL; i++)
			free(lines[i]);
		free(lines);
	}
	lines = NULL;
}

TEST basic1(void)
{
	lines = ft_readlines(fd);
	ASSERT_STR_EQ(lines[0], "line1\n");
	ASSERT_STR_EQ(lines[1], "line2\n");
	ASSERT_STR_EQ(lines[2], "line3\n");
	ASSERT_STR_EQ(lines[3], "\n");
	ASSERT_STR_EQ(lines[4], "line5\n");
	PASS();
}

SUITE (ft_readlines_suite)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(basic1);
}
