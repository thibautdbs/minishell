/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:55:55 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 17:00:03 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

t_envlst	*my_envlst_pop_front(t_envlst **penvlst)
{
	t_envlst	*first;

	if (*penvlst == NULL)
		return (NULL);
	first = *penvlst;
	*penvlst = first->next;
	first->next = NULL;
	ft_memdel(&first->content);
	ft_memdel(&first);
	return (first);
}
