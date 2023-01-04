/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstuniq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:46:47 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/30 10:29:05 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t, NULL

t_bool	ft_lstuniq(t_list *lst, size_t size)
{
	t_list	*node;
	int		i;

	i = 0;
	node = lst;
	while (node != NULL)
	{
		if (ft_lstindex(lst, node->content, size) < i)
			return (FALSE);
		node = node->next;
		i++;
	}
	return (TRUE);
}
