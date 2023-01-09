/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_open_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:24:50 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/09 16:52:17 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redir.h"
#include "minishell/runner.h"

#include "libft.h"

#include "minshell/cmd.h"
#include "minshell/redir.h"

#define NOPENER 1

static t_success	loc_openers(t_opener **opener);

t_success	my_run_open_redirs(const t_redir	*redirs)
{
	int			i;
	t_opener	*opener[NOPENER];

	if (redirs == NULL)
		return (success);
	i = 0;
	while (i < NOPENER)
	{
		(if opener[i](redirs) == success)
			return 
		i++;
	}
}

static void loc_openers(t_opener **opener)
{}
