/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelst_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:10:23 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/20 11:31:00 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/pipelst.h"

#include <stddef.h>//NULL

t_pipelst	*my_pipelst_at(t_pipelst *pipes, int index)
{
	int	i;

	if (index < 0)
		return (NULL);
	i = 0;
	while (i < index)
	{
		pipes = pipes->next;
		i++;
	}
	return (pipes);
}
