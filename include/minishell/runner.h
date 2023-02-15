/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:42:33 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/15 15:43:12 by tdubois          ###   ########.fr       */
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

int		my_run(t_cmdtree *cmd, t_envlst **penvlst, int res,
			t_cmdtree **pcmdtree);
int		my_run_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
			t_cmdtree **pcmdtree);
int		my_run_pipeline(t_cmdlst *pipeline, t_envlst **penvlst, int res,
			t_cmdtree **pcmdtree);

int		my_open_input(char *str);
int		my_open_output(char *str);
int		my_open_append(char *str);
int		my_open_heredoc(char *str);

#endif//RUNNER_H
