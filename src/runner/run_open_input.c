/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 11:32:24 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include "libft.h"

#include <unistd.h> //unlink, dup2

t_success	my_open_input(t_redir *redir)
{
	int	fd_input;

//	if (my_check_redir_label(redir->name) == failure)
//		return (failure); //Invalid label
	fd_input = open(redir->name, O_RDONLY);
	if (fd_input < 0)
		return (failure); //Error when open : doesn't exist, no perm, etc
	dup2(fd_input, STDIN);
	unlink(redir->name);
	return (success);
}
