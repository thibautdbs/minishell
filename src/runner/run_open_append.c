/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 08:54:01 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include "libft.h"

#include <unistd.h> //unlink, dup2
#include <fcntl.h> //open
#include <errno.h> //errno, perror
#include <stdio.h> //perror

int	my_open_append(char const *str)
{
	int	fd_append;

	errno = 0;
	fd_append = open(str, O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd_append < 0)
	{
		perror("minishell: Error when opening file");
		return (errno);
	}
	dup2(fd_append, STDOUT_FILENO);
	close(fd_append);
	if (errno != 0)
	{
		perror("minishell: Dup error");
		return (errno);
	}
	return (0);
}
