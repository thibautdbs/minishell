/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirlst_pop_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:53:06 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 15:53:47 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redirlst.h"

#include <stddef.h>//NULL

t_redirlst	*my_redirlst_pop_front(t_redirlst **predirlst)
{
	t_redirlst	*first;

	if (*predirlst == NULL)
		return (NULL);
	first = *predirlst;
	*predirlst = first->next;
	first->next = NULL;
	return (first);
}
