/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlst_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:58:14 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 09:45:08 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wordlst.h"

t_wordlst	*my_wordlst_at(t_wordlst *words, int index)
{
	int			i;
	t_wordlst	*curr;

	curr = words;
	i = 0;
	while (i < index)
	{
		curr = curr->next;
		i++;
	}
	return (curr);
}
