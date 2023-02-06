/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:02:15 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 12:05:43 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wordlst.h"

#include <libft.h> //ft_memset

void	my_wordlst_del(t_wordlst **word)
{
	t_wordlst	*curr;
	t_wordlst	*next;

	curr = *word;
	while (curr != NULL)
	{
		ft_memdel(&curr->content);
		next = curr->next;
		ft_memdel(&curr);
		curr = next;
	}
	*word = NULL;
}
