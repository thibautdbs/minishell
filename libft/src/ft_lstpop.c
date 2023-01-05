/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:13:26 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/22 22:51:26 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

t_list	*ft_lstpop(t_list **lst, int n)
{
	int		size;
	t_list	*node;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	size = ft_lstsize(*lst);
	if (n < 0)
		n = size + n;
	if (size == 0 || n < 0 || size <= n)
		return (NULL);
	if (n == 0)
	{
		node = *lst;
		*lst = node->next;
		node->next = NULL;
		return (node);
	}
	node = ft_lstat(*lst, n);
	ft_lstat(*lst, n - 1)->next = node->next;
	node->next = NULL;
	return (node);
}
