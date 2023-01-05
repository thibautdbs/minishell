/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:57:26 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/19 18:46:27 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

ssize_t	ft_lstindex(t_list *lst, void *content, size_t size)
{
	t_list	*node;
	int		i;

	if (content == NULL)
		return (-1);
	node = lst;
	i = 0;
	while (node != NULL)
	{
		if (node->content == NULL)
			return (-1);
		if (ft_memcmp(node->content, content, size) == 0)
		{
			return (i);
		}
		i++;
		node = node->next;
	}
	return (-1);
}
