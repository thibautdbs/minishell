/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:07:21 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:11:31 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstnew, t_list, ft_calloc
#include <stddef.h> // NULL

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *) ft_calloc(1, sizeof(t_list));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
