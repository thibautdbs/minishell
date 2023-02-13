/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:46:18 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/13 17:27:49 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUNNER_H
# define RUNNER_H

# include "libft.h"
# include "cmd.h"
# include "envlst.h"
# include "redirlst.h"

////////////////////////////////////////////////////////////////////////////////
/// TYPES

// typedef t_success	t_opener(t_redir *);

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

int	my_run(t_cmdtree *cmd, t_envlst **penvlst, int res, t_cmdtree **pcmdtree);

// t_success	my_open_input(t_redir *redir);
// t_success	my_open_output(t_redir *redir);
// t_success	my_open_append(t_redir *redir);
// t_success	my_open_heredoc(t_redir *redir);

#endif//RUNNER_H
