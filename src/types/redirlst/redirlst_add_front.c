/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirlst_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:33:45 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 16:34:21 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redirlst.h"

#include <stddef.h>//NULL

void	my_redirlst_add_front(t_redirlst **predirs, t_redirlst *new)
{
	if (*predirs != NULL)
		my_redirlst_add_back(&new, *predirs);
	*predirs = new;
}
