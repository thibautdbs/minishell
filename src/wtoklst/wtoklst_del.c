/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:40:51 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/03 13:44:06 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include "libft.h"

void	my_wtoklst_del(t_wtoklst **ptoks)
{
	t_wtoklst	*next;

	while (*ptoks != NULL)
	{
		ft_memdel(&(*ptoks)->content);
		next = (*ptoks)->next;
		ft_memdel(ptoks);
		ptoks = &next;
	}
}
