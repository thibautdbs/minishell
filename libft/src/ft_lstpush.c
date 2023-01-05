/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:35:04 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/20 03:25:17 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL
#include <stdlib.h> // malloc, free

t_list	*ft_lstpush(void const *arr, size_t nmemb, size_t size)
{
	char const	*buf;
	t_list		*lst;
	t_list		*node;

	lst = NULL;
	buf = arr;
	while (nmemb > 0)
	{
		node = ft_lstnew(ft_memdup(buf, size));
		if (node == NULL || node->content == NULL)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		ft_lstadd_back(&lst, node);
		buf += size;
		nmemb--;
	}
	return (lst);
}
