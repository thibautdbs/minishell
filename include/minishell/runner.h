/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:12:02 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 19:12:42 by ffeaugas         ###   ########.fr       */
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

int	my_run(t_cmdtree *cmd, t_envlst **penvlst, int res,
		t_cmdtree **pcmdtree);
int	my_run_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
		t_cmdtree **pcmdtree);
int	my_run_pipeline(t_cmdlst *pipeline, t_envlst **penvlst, int res,
		t_cmdtree **pcmdtree);

int	my_redirect(t_redirlst *redir, t_envlst *envlst, int res);

int	my_execve(t_wordlst *wordlst, t_envlst *envlst);

int	my_get_path(char *buf, char const *name, t_envlst *envlst);

int	my_open_input(char *str);
int	my_open_output(char *str);
int	my_open_append(char *str);
int	my_open_heredoc(char *str);

#endif//RUNNER_H
