/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_del_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 02:17:24 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/04 02:18:17 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include "libft.h"

void	my_wtoklst_del_one(t_wtoklst **ptok)
{
	ft_memdel(&(*ptok)->content);
	ft_memdel(ptok);
}
