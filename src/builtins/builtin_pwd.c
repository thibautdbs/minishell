/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/16 10:01:53 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h>//NULL
#include <stdlib.h>//EXIT_SUCCESS
#include <unistd.h>//getcwd
#include <limits.h>//PATH_MAX
#include <errno.h>//errno
#include <stdio.h>//perror

#include "libft.h" //ft_putendl_fd

int	my_builtin_pwd(void)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		perror("minishell: pwd");
		return (errno);
	}
	ft_putendl_fd(pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
