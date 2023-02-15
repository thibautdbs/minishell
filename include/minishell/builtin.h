/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:29:43 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 17:35:37 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "libft.h"
# include "envlst.h"

////////////////////////////////////////////////////////////////////////////////
/// PRIVATE

t_bool	my_is_builtin(char	*cmd);

int			my_builtin_env(t_envlst *env, char **args);

int			my_builtin_export(t_envlst *env, char **args);
int			my_print_export(t_envlst *env);
t_success	my_add_var(t_envlst *env, char *var);
t_success	my_append_var(t_envlst *env, char *var);
t_success	my_overwrite_var(t_envlst *env, char *var);

int			my_builtin_exit(t_envlst *env, char **args);

int			my_builtin_unset(t_envlst *env, char **args);

int			my_builtin_echo(t_envlst *env, char **args);

int			my_builtin_pwd(t_envlst *env, char **args);

int			my_builtin_cd(t_envlst *env, char **args);

t_success	my_check_varname(char	*var, char delim);
char		*my_get_pwd(void);

#endif //BUILTIN_H
