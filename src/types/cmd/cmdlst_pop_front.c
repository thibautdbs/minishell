/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:45:43 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 15:47:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

t_cmdlst	*my_cmdlst_pop_front(t_cmdlst **pcmdlst)
{
	t_cmdlst	*first;

	if (*pcmdlst == NULL)
		return (NULL);
	first = *pcmdlst;
	*pcmdlst = first->next;
	first->next = NULL;
	return (first);
}
