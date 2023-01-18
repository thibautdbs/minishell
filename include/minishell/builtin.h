/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:29:43 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/18 20:07:18 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "libft.h"
# include "env.h"

////////////////////////////////////////////////////////////////////////////////
/// PRIVATE

int	my_builtin_env(t_env *env, char **args);

int			my_builtin_export(t_env *env, char **args);
int			my_print_export(t_env *env);
t_success	my_add_var(t_env *env, char *var);
t_success	my_append_var(t_env *env, char *var);
t_success	my_overwrite_var(t_env *env, char *var);

int	my_builtin_exit(t_env *env, char **args);

int	my_builtin_unset(t_env *env, char **args);

int	my_builtin_echo(t_env *env, char **args);

int	my_builtin_pwd(t_env *env, char **args);

t_success my_check_varname(char	*var, char delim);

#endif //BUILTIN_H
