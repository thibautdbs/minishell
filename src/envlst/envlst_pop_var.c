/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_pop_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:40:30 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/20 17:48:41 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

//TODO ici il faut copier le comportement de find_var avec **penvlst,
//puis pop_front. sinon mauvais pointeur modifié
void		my_envlst_pop_var(char *var, t_envlst **penvlst)
{
	t_envlst	*curr;

	curr = my_envlst_find_var(var, *penvlst);
	if (curr == NULL)
		return ;
	my_envlst_pop_front(&curr);
}
