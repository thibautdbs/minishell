/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:12:11 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/20 01:18:52 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL
#include <stdlib.h> // free

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
	{
		return ;
	}
	if (del != NULL && lst->content != NULL)
	{
		(*del)(lst->content);
	}
	free(lst);
}
