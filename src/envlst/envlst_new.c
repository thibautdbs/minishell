/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:10:23 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/10 12:38:58 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include "libft.h" //ft_strdup
#include <stddef.h> //NULL

t_envlst	*my_envlst_new(char const *str)
{
	t_envlst	*env;

	env = ft_calloc(1, sizeof(t_envlst));
	if (env == NULL)
		return (NULL);
	env->next = NULL;
	env->content = ft_strdup(str);
	if (env->content == NULL)
	{
		ft_memdel(&env);
		return (NULL);
	}
	return (env);
}
