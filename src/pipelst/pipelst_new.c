/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:10:23 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/14 11:29:15 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/pipelst.h"

#include "libft.h" //ft_memdel
#include <stddef.h> //NULL
#include <unistd.h> //pipe

t_pipelst	*my_pipelst_new(void)
{
	t_pipelst	*p;

	p = ft_calloc(1, sizeof(t_pipelst));
	if (p == NULL)
		return (NULL);
	p->next = NULL;
	if (pipe(p->fd) < 0)
	{
		ft_memdel(&p);
		return (NULL);
	}
	p->in = &p->fd[1];
	p->out = &p->fd[0];
	return (p);
}
