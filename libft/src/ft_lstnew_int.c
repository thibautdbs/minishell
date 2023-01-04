/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:38:52 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 22:48:51 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL
#include <stdlib.h> // malloc, free

t_list	*ft_lstnew_int(int n)
{
	t_list	*node;
	int		*buf;

	node = (t_list *) malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	buf = (int *) malloc(sizeof(int));
	if (buf == NULL)
	{
		free(node);
		return (NULL);
	}
	*buf = n;
	node->content = buf;
	node->next = NULL;
	return (node);
}
