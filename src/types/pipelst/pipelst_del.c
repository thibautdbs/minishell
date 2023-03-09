/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:02:15 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/14 11:34:20 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/pipelst.h"

#include <libft.h> //ft_memset
#include <unistd.h> //close

void	my_pipelst_del(t_pipelst **pipes)
{
	t_pipelst	*curr;
	t_pipelst	*next;

	curr = *pipes;
	while (curr != NULL)
	{
		close(curr->fd[0]);
		close(curr->fd[1]);
		next = curr->next;
		ft_memdel(&curr);
		curr = next;
	}
	*pipes = NULL;
}
