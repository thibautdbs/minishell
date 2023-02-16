/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:29 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/16 10:25:50 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdbool.h>

# include "libft.h"
# include "envlst.h"
# include "wordlst.h"

////////////////////////////////////////////////////////////////////////////////
/// PRIVATE

bool		my_is_builtin(char	*cmd);

int			my_builtin(t_wordlst *words, t_envlst *penvlst);

int			my_builtin_env(char **args, t_envlst *penvlst);

int			my_builtin_export(char **args, t_envlst *penvlst);
int			my_print_export(t_envlst *env);
t_success	my_add_var(char *var, t_envlst *penvlst);
t_success	my_append_var(char *var, t_envlst *penvlst);
t_success	my_overwrite_var(char *var, t_envlst *penvlst);

int			my_builtin_exit(char **args);

int			my_builtin_unset(char **args, t_envlst *penvlst);

int			my_builtin_echo(char **args);

int			my_builtin_pwd(void);

int			my_builtin_cd(char **args, t_envlst *penvlst);

t_success	my_check_varname(char	*var, char delim);
char		*my_get_pwd(void);

#endif //BUILTIN_H
