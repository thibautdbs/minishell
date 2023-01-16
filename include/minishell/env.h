/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:29:43 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/16 12:04:00 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env t_env;

typedef struct s_env
{
	char	*content;
	t_env	*next;
}	t_env;

////////////////////////////////////////////////////////////////////////////////
/// PRIVATE

t_env	*my_env_init(char	**envp);
char	**my_get_envp(t_env *env);
int		my_env_size(t_env *env);
t_env	*my_env_create(char const *str);
void	my_env_addback(t_env **env, t_env *to_add);
void	my_env_destroy(t_env **env);
void	my_sort_env(char **envp);

#endif //ENV_H
