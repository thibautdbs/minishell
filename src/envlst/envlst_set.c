/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:04:09 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 16:43:11 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include "libft.h" //t_success

t_success	my_envlst_set(char *var, t_envlst **penvlst)
{
	t_envlst	*new;

	new = my_envlst_new(var);
	if (new == NULL)
	{
		ft_puterr("Error occured when creating var");
		return (FAILURE);
	}
	my_envlst_addback(penvlst, new);
	return (SUCCESS);
}
