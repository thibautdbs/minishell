/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:12:02 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/21 14:29:19 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUNNER_H
# define RUNNER_H

# include "libft.h"
# include "cmd.h"
# include "envlst.h"
# include "redirlst.h"

////////////////////////////////////////////////////////////////////////////////
/// RUNNER

int		my_run(t_cmdtree *cmd, t_envlst **penvlst, int res,
			t_cmdtree **pcmdtree);
int		my_run_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
			t_cmdtree **pcmdtree);
int		my_run_pipeline(t_cmdlst *pipeline, t_envlst **penvlst, int res,
			t_cmdtree **pcmdtree);

int		my_execve(t_wordlst *wordlst, t_envlst *envlst);

int		my_get_path(char *buf, char const *name, t_envlst *envlst);

////////////////////////////////////////////////////////////////////////////////
/// redirect

int		my_redirect(t_redirlst *redir, t_envlst *envlst, int res);

int		my_redirect_one_heredoc(t_wordlst const *lines, t_redirlst_t type,
			t_envlst *envlst, int res);

int		my_redirect_one_infile(char const *file_name);
int		my_redirect_one_outfile(char const *file_name);
int		my_redirect_one_appnd(char const *file_name);

#endif//RUNNER_H
