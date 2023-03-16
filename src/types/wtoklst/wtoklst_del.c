/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:40:51 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/04 02:19:51 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include "libft.h"

void	my_wtoklst_del(t_wtoklst **ptoks)
{
	t_wtoklst	*tok;

	while (*ptoks != NULL)
	{
		tok = my_wtoklst_pop_front(ptoks);
		my_wtoklst_del_one(&tok);
	}
}
