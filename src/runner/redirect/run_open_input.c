/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 08:51:09 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include "libft.h"

#include <unistd.h> //unlink, dup2
#include <fcntl.h> //open
#include <errno.h> //errno, perror
#include <stdio.h> //perror

int	my_open_input(char const *str)
{
	int	fd_input;

	errno = 0;
	fd_input = open(str, O_RDONLY);
	if (fd_input < 0)
	{
		perror("minishell: Error when opening file");
		return (errno);
	}
	dup2(fd_input, STDIN_FILENO);
	close(fd_input);
	if (errno != 0)
	{
		perror("minishell: Dup error");
		return (errno);
	}
	return (0);
}
