/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_varname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:15 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/16 17:26:59 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include "libft.h" //t_success, ft_isalpha, ft_isalnum

bool	my_is_valid_identifier(char *var, char delim)
{
	int	i;

	if (ft_isalpha(var[0]) == 0 && var[0] != '_')
		return (FAILURE);
	i = 1;
	while (var[i] && var[i] != delim)
	{
		if (delim == '=' && var[i] == '+' && var[i + 1] == '=')
			break ;
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
