/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:38:45 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/24 18:44:57 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstget_int(t_list *node)
{
	if (node == NULL || node->content == NULL)
		return (0);
	return (*(int *)node->content);
}
