/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:02:15 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 16:38:43 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <libft.h> //ft_memset

void	my_envlst_del(t_envlst **penvlst)
{
	t_envlst	*curr;
	t_envlst	*next;

	curr = *penvlst;
	while (curr != NULL)
	{
		ft_memdel(&curr->content);
		next = curr->next;
		ft_memdel(&curr);
		curr = next;
	}
	*penvlst = NULL;
}
