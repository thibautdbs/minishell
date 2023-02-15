/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:46:18 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 15:21:23 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUNNER_H
# define RUNNER_H

# include "libft.h"
# include "cmd.h"
# include "envlst.h"
# include "redirlst.h"
# include "pipelst.h"

////////////////////////////////////////////////////////////////////////////////
/// TYPES

// typedef t_success	t_opener(t_redir *);

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

int	my_run(t_cmdtree *cmd, t_envlst **penvlst, int res, t_cmdtree **pcmdtree);
int	my_run_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
		t_cmdtree **pcmdtree);
//utils
void	my_close_stdfds(void);
int		my_dup_pipe(t_pipelst *pipes, int i);
void	my_wait_children(void);
int		my_open_input(char *str);
int		my_open_output(char *str);
int		my_open_append(char *str);
int		my_open_heredoc(char *str);

#endif//RUNNER_H
