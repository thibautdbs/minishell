/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/14 13:44:27 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include "libft.h"

#include <unistd.h> //unlink, dup2
#include <fcntl.h> //open
#include <errno.h> //errno, perror
#include <stdio.h> //perror

int	my_open_input(char *str)
{
	int	fd_input;

	errno = 0;
	fd_input = open(str, O_RDONLY);
	if (fd_input < 0)
		perror("Error when opening file");
	else
	{
		dup2(fd_input, STDIN);
		if (errno != 0)
		{
			perror("Dup error");
			close(fd_input);
		}
		else
			unlink(str);
	}
	return (errno);
}
