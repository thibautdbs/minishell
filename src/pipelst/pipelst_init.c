/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:10:23 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/14 11:41:54 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/pipelst.h"

#include <stddef.h> //NULL

t_pipelst	*my_pipelst_init(int len)
{
	t_pipelst	*pipes;
	t_pipelst	*new;
	int	i;

	i = 0;
	while (i < len)
	{
		new = my_pipelst_new();
		if (new == NULL)
		{
			my_pipelst_del(&pipes);
			return (NULL);
		}
		my_pipelst_add_back(&pipes, new);
		i++;
	}
	return (pipes);
}
