/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:35:10 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 17:48:30 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <errno.h>

#include "minishell/envlst.h"
#include "minishell/wordlst.h"

void	my_expand_words(t_wordlst **pwords, t_envlst *envlst)
{
	t_wordlst	*curr;
	t_wordlst	*new_words;
	t_wordlst	*expanded_words;

	errno = 0; 
	curr = *pwords;
	while (curr != NULL)
	{
		new_words = my_expand(curr->content, envlst);
		if (errno != 0)
			break ;
		my_wordlst_add_back(&expanded_words, new_words);
	}
	my_wordlst_del(pwords);
	pwords = &expanded_words;
}
