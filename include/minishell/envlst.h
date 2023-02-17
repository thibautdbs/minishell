/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:29:43 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 17:24:28 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVLST_H
# define ENVLST_H

#include "libft.h" //t_success

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef struct s_envlst	t_envlst;

typedef struct s_envlst
{
	char		*content;
	t_envlst	*next;
}	t_envlst;

typedef enum e_var_operation_t
{
	VAR_DEFINE,
	VAR_REPLACE,
	VAR_APPND,
	VAR_NO_ACTION,
}	t_var_operation_t;

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

t_envlst	*my_envlst_init(char **envp);
char		**my_envlst_to_envp(t_envlst *envlst);
int			my_envlst_size(t_envlst *envlst);
t_envlst	*my_envlst_new(char const *str);
void		my_envlst_addback(t_envlst **envlst, t_envlst *to_add);
void		my_envlst_pop_var(char *var, t_envlst **penvlst);
t_envlst	*my_envlst_pop_front(t_envlst **penvlst);
void		my_envlst_del(t_envlst **penvlst);
void		my_sort_envp(char **envp);
t_envlst	*my_envlst_find_var(char const *var, t_envlst *envlst);
char		*my_envlst_get_value(char *var, t_envlst *envlst);
t_success	my_envlst_set(char *var, t_envlst **penvlst);
t_success	my_envlst_appnd(char *var, t_envlst **penvlst);
t_success	my_envlst_apply(char *var, t_envlst **penvlst);

#endif //ENVLST_H
