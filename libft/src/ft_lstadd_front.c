/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:34:41 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:16:21 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstadd_front, t_list
#include <stddef.h> // NULL

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}
