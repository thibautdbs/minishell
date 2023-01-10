/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 13:38:12 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include "libft.h"

#include <unistd.h> //unlink, dup2
#include <fcntl.h> //open

t_success	my_open_input(t_redir *redir)
{
	int	fd_input;

//	if (my_check_redir_label(redir->name) == failure)
//		return (failure); //Invalid label
	fd_input = open(redir->label, O_RDONLY);
	if (fd_input < 0)
		return (FAILURE); //Error when open : doesn't exist, no perm, etc
	dup2(fd_input, STDIN);
	unlink(redir->label);
	return (SUCCESS);
}
