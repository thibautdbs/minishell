/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_to_envp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:36:28 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/14 09:13:14 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include "libft.h" //ft_calloc, ft_strdup, ft_strsdel

char	**my_envlst_to_envp(t_envlst *envlst)
{
	char	**envp;
	int		i;

	envp = ft_calloc(my_envlst_size(envlst) + 1, sizeof(char *));
	if (envp == NULL)
		return (NULL);
	i = 0;
	while (envlst != NULL)
	{
		envp[i] = ft_strdup(envlst->content);
		if (envp[i] == NULL)
		{
			ft_strsdel(&envp);
			return (NULL);
		}
		envlst = envlst->next;
		i++;
	}
	return (envp);
}
