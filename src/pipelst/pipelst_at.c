/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelst_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:10:23 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/14 11:48:13 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/pipelst.h"

#include <stddef.h> //NULL

t_pipelst	*my_pipelst_at(t_pipelst *pipes, int index)
{
	int			i;
	t_pipelst	*curr;

	curr = pipes;
	i = 0;
	while (i < index)
	{
		curr = curr->next;
		i++;
	}
	return (curr);
}
