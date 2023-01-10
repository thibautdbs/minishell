/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:24:50 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 10:52:05 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redir.h"
#include "minishell/runner.h"

#include "libft.h"

#include "minshell/cmd.h"
#include "minshell/redir.h"

#define NOPENER 1

static t_success	loc_openers(t_opener **opener);

t_success	my_run_open_redirs(const t_redir	*redir)
{
	t_opener	*opener[NOPENER];

	if (redir == NULL)
		return (success);
	if (opener[redir->type](redir) == failure)
		return (failure);
	my_run_open_redirs(redir->next);
}

static void loc_openers(t_opener **opener)
{
	opener[INPUT] = my_open_input;
//	opener[HEREDOC] = my_open_heredoc;
//	opener[OUTPUT] = my_open_output;
//	opener[APPEND] = my_open_append;
}
