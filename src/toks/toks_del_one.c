/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks_del_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 14:02:10 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/toks.h"

#include "libft.h"
#include <stddef.h>//NULL

void	my_toks_del_one(t_toks **toks)
{
	if (*toks == NULL)
		return ;
	ft_memdel(&(*toks)->content);
	ft_memdel(toks);
}