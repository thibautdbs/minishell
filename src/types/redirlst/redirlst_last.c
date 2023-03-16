/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirlst_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:23:37 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 16:24:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redirlst.h"

#include <stddef.h>//NULL

t_redirlst	*my_redirlst_last(t_redirlst *redirs)
{
	while (redirs->next != NULL)
		redirs = redirs->next;
	return (redirs);
}
