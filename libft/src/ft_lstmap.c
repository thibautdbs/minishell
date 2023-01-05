/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:02:41 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:15:47 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstmap, ft_lstnew, ft_lstclear, ft_lstadd_back, t_list
#include <stddef.h> // NULL

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_lst;
	t_list	*mapped_node;

	if (lst == NULL || f == NULL || del == NULL)
	{
		return (NULL);
	}
	mapped_lst = NULL;
	while (lst != NULL)
	{
		mapped_node = ft_lstnew((*f)(lst->content));
		if (mapped_node == NULL)
		{
			ft_lstclear(&mapped_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped_lst, mapped_node);
		lst = lst->next;
	}
	return (mapped_lst);
}
