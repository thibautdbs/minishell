/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:08:28 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/20 09:50:24 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <stddef.h>//NULL
#include <stdio.h>//perror

#include "libft.h"
#include "minishell/envlst.h"
#include "minishell/wordlst.h"
#include "minishell/wtoklst.h"

static t_wordlst	*loc_wtoklst2wordlst(t_wtoklst *toks);

t_wordlst	*my_expand(char const *word, t_envlst *envlst)
{
	t_wtoklst	*toks;
	t_wordlst	*args;

	toks = my_wtoklst_extract(word);
	my_expand_vars(&toks, envlst);
	my_expand_qtd_vars(toks, envlst);
	my_wtoklst_concat(&toks);
	my_expand_wildcards(&toks);
	my_wtoklst_concat(&toks);
	args = loc_wtoklst2wordlst(toks);
	my_wtoklst_del(&toks);
	return (args);
}

static t_wordlst	*loc_wtoklst2wordlst(t_wtoklst *toks)
{
	t_wordlst	*words;
	t_wordlst	*tmp;

	words = NULL;
	while (toks != NULL)
	{
		if (toks->type != BLANKS)
		{
			tmp = my_wordlst_new();
			if (tmp == NULL)
			{
				my_wordlst_del(&words);
				return (NULL);
			}
			tmp->content = ft_strdup(toks->content);
			my_wordlst_add_back(&words, tmp);
		}
		toks = toks->next;
	}
	return (words);
}
