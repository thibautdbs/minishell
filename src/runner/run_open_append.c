/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:28:56 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 18:06:04 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include "libft.h"

#include <unistd.h> //unlink, dup2
#include <fcntl.h> //open

t_success	my_open_append(t_redir *redir)
{
	int	fd_append;

//	if (my_check_redir_label(redir->name) == failure)
//		return (failure); //Invalid label
	fd_append = open(redir->label, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd_append < 0)
		return (FAILURE); //Error when creating or accessing
	dup2(fd_append, STDOUT);
	unlink(redir->label);
	return (SUCCESS);
}
