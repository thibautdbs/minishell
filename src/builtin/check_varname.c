/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_varname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:15 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/17 19:16:50 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //t_success, ft_isalpha, ft_isalnum

#include "minishell/builtin.h"

t_success my_check_varname(char	*var, char delim)
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
