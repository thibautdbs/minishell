/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:24:50 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/24 12:25:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include "libft.h"

#include "minishell/redir.h"

#define NOPENER 1

static t_success	loc_openers(t_opener **opener);

t_success	my_run_open_redirs(t_redir	*redir)
{
	t_opener	*opener[NOPENER];

	loc_openers(opener);
	if (redir == NULL)
		return (SUCCESS);
	if (opener[redir->type](redir) == FAILURE)
		return (FAILURE);
	my_run_open_redirs(redir->next);
	return (SUCCESS);
}

static t_success	loc_openers(t_opener **opener)
{
	opener[INPUT] = my_open_input;
	opener[HEREDOC] = my_open_heredoc;
	opener[OUTPUT] = my_open_output;
	opener[APPEND] = my_open_append;
	return (SUCCESS);
}
