/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:35:10 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 09:45:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <errno.h>

#include "minishell/envlst.h"
#include "minishell/wordlst.h"

void	my_expand_words(t_wordlst **pwords, t_envlst *envlst, int res)
{
	t_wordlst	*curr;
	t_wordlst	*new_words;
	t_wordlst	*expanded_words;

	errno = 0;
	curr = *pwords;
	expanded_words = NULL;
	while (curr != NULL)
	{
		new_words = my_expand(curr->content, envlst, res);
		if (errno != 0)
			break ;
		my_wordlst_add_back(&expanded_words, new_words);
		curr = curr->next;
	}
	my_wordlst_del(pwords);
	*pwords = expanded_words;
}
