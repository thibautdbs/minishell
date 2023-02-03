/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:41:56 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/03 16:27:42 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/env.h"
#include "minishell/wtoklst.h"

void	my_expand_vars(t_wtoklst **ptoks, t_env *env, t_wtoklst_t var_type)
{
	char	*value;

	while ((*ptoks) != NULL)
	{
		if ((*ptoks)->type == var_type)
		{
			value = my_env_get_value(env, (*ptoks)->content);
			if (value == NULL)
				value = "";
			(*ptoks)->type = CHARS;
			(*ptoks)->content = ft_strdup(value);
		}
		ptoks = &(*ptoks)->next;
	}
}
