/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstflat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:38:05 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/28 15:30:03 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

void	*ft_lstflat(t_list *lst, size_t size)
{
	char	*arr;
	char	*cell;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	arr = ft_calloc(ft_lstsize(lst), size);
	if (arr == NULL)
		return (NULL);
	cell = arr;
	node = lst;
	while (node != NULL)
	{
		ft_memcpy(cell, node->content, size);
		node = node->next;
		cell += size;
	}
	return (arr);
}
