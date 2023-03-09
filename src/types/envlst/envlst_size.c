/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:18:45 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 16:39:46 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <stddef.h> //NULL

int	my_envlst_size(t_envlst *envlst)
{
	int			i;
	t_envlst	*curr;

	i = 0;
	curr = envlst;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
