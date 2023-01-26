/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:36:28 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/24 12:13:41 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/env.h"

static void	loc_destroy_envp(char ***envp, int stop);

char	**my_get_envp(t_env *env)
{
	char	**envp;
	int		i;
	int		len;
	t_env	*curr;

	len = my_env_size(env);
	envp = ft_calloc(my_env_size(env) + 1, sizeof(char *));
	if (envp == NULL)
		return (NULL);
	i = 0;
	curr = env;
	while (i < len)
	{
		envp[i] = ft_strdup(curr->content);
		if (envp[i] == NULL)
		{
			loc_destroy_envp(&envp, i);
			return (NULL);
		}
		i++;
		curr = curr->next;
	}
	envp[len] = NULL;
	return (envp);
}

static void	loc_destroy_envp(char ***envp, int stop)
{
	int	i;

	if (*envp == NULL)
		return ;
	i = 0;
	while (i < stop && (*envp)[i] != NULL)
	{
		ft_memdel(&(*envp)[i]);
		i++;
	}
	ft_memdel(envp);
}