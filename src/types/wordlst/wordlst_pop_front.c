/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlst_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:28:33 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/09 15:41:54 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wordlst.h"

#include <stddef.h>//NULL
#include "libft.h" //ft_memdel

t_wordlst	*my_wordlst_pop_front(t_wordlst **wordlst)
{
	t_wordlst	*first;

	if (*wordlst == NULL)
		return (NULL);
	first = *wordlst;
	*wordlst = first->next;
	first->next = NULL;
	return (first);
}
