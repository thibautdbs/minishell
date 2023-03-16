/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:29 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/14 12:14:43 by tdubois          ###   ########.fr       */
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

int			my_builtin_export(t_wordlst *words, t_envlst **penvlst);
int			my_print_export(t_envlst *env);
t_success	my_add_var(char *str, t_envlst **penvlst);
t_success	my_append_var(char *str, t_envlst **penvlst);
t_success	my_overwrite_var(char *str, t_envlst **penvlst);

/// REWORKED
int			my_builtin(t_wordlst *words, t_envlst **penvlst, int res);
bool		my_is_builtin(char const *cmd);
int			my_builtin_pwd(void);
int			my_builtin_echo(t_wordlst *words);
int			my_builtin_cd(t_wordlst *words, t_envlst **penvlst);
int			my_builtin_exit(t_wordlst *words, int res);
int			my_builtin_env(t_wordlst *words, t_envlst *envlst);

int			my_builtin_unset(t_wordlst *words, t_envlst **penvlst);
bool		my_is_valid_identifier(char *var, char delim);

#endif //BUILTIN_H
