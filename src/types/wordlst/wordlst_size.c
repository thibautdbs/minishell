/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:46:37 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/15 16:48:01 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wordlst.h"

#include <stddef.h>//NULL

int	my_wordlst_size(t_wordlst *wordlst)
{
	int	size;

	size = 0;
	while (wordlst != NULL)
	{
		size++;
		wordlst = wordlst->next;
	}
	return (size);
}
