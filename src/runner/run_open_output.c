/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/14 13:43:56 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include "libft.h"

#include <unistd.h> //unlink, dup2
#include <fcntl.h> //open
#include <errno.h> //errno, perror
#include <stdio.h> //perror

int	my_open_output(char *str)
{
	int	fd_output;

	errno = 0;
	fd_output = open(str, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_output < 0)
		perror("Error when opening file");
	else
	{
		dup2(fd_output, STDOUT);
		if (errno != 0)
		{
			perror("Dup error");
			close(fd_output);
		}
		else
			unlink(str);
	}
	return (errno);
}
