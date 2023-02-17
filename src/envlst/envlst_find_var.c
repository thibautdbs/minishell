/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_find_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:56:28 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 10:54:52 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include "libft.h" //ft_strncmp
#include <stddef.h> //NULL

t_envlst	*my_envlst_find_var(char const *var, t_envlst *envlst)
{
	int			var_label_len;
	t_envlst	*curr;

	var_label_len = ft_strcspn(var, "+=");
	curr = envlst;
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
