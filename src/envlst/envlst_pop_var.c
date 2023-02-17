/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_pop_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:40:30 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 17:21:22 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

void		my_envlst_pop_var(char *var, t_envlst **penvlst)
{
	t_envlst	*curr;

	curr = my_envlst_find_var(var, *penvlst);
	if (curr == NULL)
		return ;
	my_envlst_addback(penvlst, my_envlst_pop_front(&curr));
}
