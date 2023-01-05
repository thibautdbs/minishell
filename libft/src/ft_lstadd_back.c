/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:00:03 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:26:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstadd_back, ft_lstlast, t_list
#include <stddef.h> // NULL

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		(ft_lstlast(*lst))->next = new;
	}
}
