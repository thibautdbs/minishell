/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:08:28 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/02 15:31:13 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <errno.h>//errno
#include <stddef.h>//NULL
#include <stdio.h>//perror

#include "minishell/wordlst.h"
#include "minishell/wtoklst.h"

t_wordlst	*my_expand(char const *word)
{
	t_wtoklst	*toks;
	t_wordlst	*args;

	errno = 0;
	toks = my_wtok_extract(word);
	toks = my_expand_vars(toks);
	toks = my_expand_qtd_vars(toks);
	toks = my_expand_wildcard(toks);
	args = my_wtok_to_words(toks);
	my_wtoklst_del(&toks);
	if (errno != 0)
	{
		perror("minishell:");
		my_wordlst_del(&args);
		return (NULL);
	}
	return (args);
}
