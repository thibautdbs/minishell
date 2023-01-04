/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstload.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:42:51 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/24 14:44:44 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

t_list	*ft_lstload(void *ptrs, size_t nmemb)
{
	char	**buf;
	t_list	*lst;
	t_list	*node;
	size_t	i;

	if (ptrs == NULL || nmemb == 0)
		return (NULL);
	i = 0;
	lst = NULL;
	buf = ptrs;
	while (i < nmemb)
	{
		node = ft_lstnew(buf[i]);
		if (node == NULL)
		{
			ft_lstclear(&lst, NULL);
			return (NULL);
		}
		ft_lstadd_back(&lst, node);
		i++;
	}
	return (lst);
}
