/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:40:01 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/22 18:08:48 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

t_list	*ft_lstat(t_list *lst, int n)
{
	int const	size = ft_lstsize(lst);
	t_list		*node;
	int			i;

	if (n < 0)
		n = size + n;
	if (n < 0 || size <= n)
		return (NULL);
	i = 0;
	node = lst;
	while (node != NULL)
	{
		if (i == n)
			return (node);
		i++;
		node = node->next;
	}
	return (NULL);
}
