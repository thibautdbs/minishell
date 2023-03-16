/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:27:57 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 11:44:55 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <stddef.h> //NULL

#include "libft.h" //ft_strncmp, ft_strlen

static int	loc_envp_len(char **envp);

void	my_sort_envp(char **envp)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	len = loc_envp_len(envp);
	i = 0;
	while (i < len - 2)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ft_strncmp(envp[j], envp[j + 1], ft_strlen(envp[j] + 1)) > 0)
			{
				tmp = envp[j];
				envp[j] = envp[j + 1];
				envp[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	loc_envp_len(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}
