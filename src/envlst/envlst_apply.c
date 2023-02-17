/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:48:25 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 17:10:23 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <stddef.h> //NULL
#include "libft.h" //t_success, ft_strcspn, ft_strchr

static t_var_operation_t loc_get_operation_type(char const *var,
	t_envlst *envlst);

t_success	my_envlst_apply(char *var, t_envlst **penvlst)
{
	t_var_operation_t	op;

	op = loc_get_operation_type(var, *penvlst);
	if (op == VAR_NO_ACTION)
		return (SUCCESS);
	if (op == VAR_APPND)
		return (my_envlst_appnd(var, penvlst));
	if (op == VAR_REPLACE)
		my_envlst_pop_var(var, penvlst);
	return (my_envlst_set(var, penvlst));
}

static t_var_operation_t loc_get_operation_type(char const *var,
	t_envlst *envlst)
{
	t_envlst *var_location;

	var_location = my_envlst_find_var(var, envlst);
	if (var_location != NULL && ft_strchr(var, '=') == NULL)
		return (VAR_NO_ACTION);
	if (ft_strchr(var, '=') == NULL || var_location == NULL)
		return (VAR_DEFINE);
	if (ft_strcspn(var, "+") < ft_strcspn(var, "="))
		return (VAR_APPND);
	return (VAR_REPLACE);
}
