/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:40:51 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/03 18:56:15 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include "libft.h"

void	my_wtoklst_del(t_wtoklst **ptoks)
{
	t_wtoklst	*tok;
	t_wtoklst	*next;

	tok = *ptoks;
	while (tok != NULL)
	{
		ft_memdel(&tok->content);
		next = tok->next;
		ft_memdel(&tok);
		tok = next;
	}
	*ptoks = NULL;
}
