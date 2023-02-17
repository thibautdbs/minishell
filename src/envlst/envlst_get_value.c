/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_get_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:56:28 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 17:24:17 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <stddef.h> //NULL
#include "libft.h" //ft_strchr

char	*my_envlst_get_value(char *var, t_envlst *envlst)
{
	t_envlst	*curr;
	char		*substr;

	curr = my_envlst_find_var(var, envlst);
	if (curr == NULL)
		return (NULL);
	substr = ft_strchr(curr->content, '=');
	if (substr == NULL)
		return (NULL);
	return (substr++);
}
