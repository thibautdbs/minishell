/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:29:43 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 19:01:16 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVLST_H
# define ENVLST_H

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef struct s_envlst	t_envlst;

typedef struct s_envlst
{
	char		*content;
	t_envlst	*next;
}	t_envlst;

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

t_envlst	*my_envlst_init(char **envp);
char		**my_envlst_to_envp(t_envlst *envlst);
int			my_envlst_size(t_envlst *env);
t_envlst	*my_envlst_new(char const *str);
void		my_envlst_addback(t_envlst **envlst, t_envlst *to_add);
void		my_envlst_del(t_envlst **env);
void		my_sort_envp(char **envp);
t_envlst	*my_envlst_find_var(t_envlst *env, char const *var);
char		*my_envlst_get_value(t_envlst *env, char const *var);

#endif //ENVLST_H
