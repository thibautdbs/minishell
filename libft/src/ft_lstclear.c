/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:22:54 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/19 15:51:39 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstclear, ft_lstdelone, t_list
#include <stddef.h> // NULL

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}
