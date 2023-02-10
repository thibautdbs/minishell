/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_find_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:56:28 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/10 12:39:37 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include "libft.h" //ft_strncmp
#include <stddef.h> //NULL

static int	loc_get_var_label_len(char *var)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=' && var[i] != '+')
		i++;
	return (i);
}

t_envlst	*my_envlst_find_var(t_envlst *env, char *var)
{
	int			var_label_len;
	t_envlst	*curr;

	var_label_len = loc_get_var_label_len(var);
	curr = env;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->content, var, var_label_len) == 0
			&& (curr->content[var_label_len] == '='
				|| curr->content[var_label_len] == '\0'))
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
