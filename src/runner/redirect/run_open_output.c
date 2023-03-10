/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 08:46:06 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <unistd.h> //dup2
#include <fcntl.h> //open
#include <errno.h> //errno
#include <stdio.h> //perror

int	my_open_output(char const *str)
{
	int	fd_output;

	errno = 0;
	fd_output = open(str, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd_output < 0)
	{
		perror("minishell: Error when opening file");
		return (errno);
	}
	dup2(fd_output, STDOUT_FILENO);
	close(fd_output);
	if (errno != 0)
	{
		perror("minishell: Dup error");
		return (errno);
	}
	return (0);
}
