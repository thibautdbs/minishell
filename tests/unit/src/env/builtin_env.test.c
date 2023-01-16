/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:39:04 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/17 00:23:14 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

static int	fd;

static void	setup(void *data)
{
	(void) data;
	fd = 0;
	fd = open(O_TMPFILE);
	dup();
}

static void	teardown(void *data)
{
	(void) data;
	reset_dup();
	close(fd);
}

TEST	test1()
{
	
}

SUITE(test_env_builtin_fct)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(setup, NULL);
}
