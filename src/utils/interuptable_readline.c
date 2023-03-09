/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interuptable_readline.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:55:31 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/09 16:09:07 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/utils.h"

#include <readline/readline.h> //readline
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stddef.h>

#include "libft.h"

int	my_interuptable_readline(char const *prompt, char **ret_buf)
{
	int	saved_stdin;

	*ret_buf = NULL;
	saved_stdin = dup(STDIN_FILENO);
	if (saved_stdin == -1)
		return (errno);
	*ret_buf = readline(prompt);
	if (dup2(saved_stdin, STDIN_FILENO) == -1)
	{
		close(saved_stdin);
		ft_memdel(ret_buf);
		perror("minishell:");
		return (errno);
	}
	return (EXIT_SUCCESS);
}
