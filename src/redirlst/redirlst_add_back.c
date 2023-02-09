/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirlst_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:22:04 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 16:23:07 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redirlst.h"

#include <stddef.h>//NULL

void	my_redirlst_add_back(t_redirlst **predirs, t_redirlst *new)
{
	if (*predirs == NULL)
	{
		*predirs = new;
		return ;
	}
	my_redirlst_last(*predirs)->next = new;
}
