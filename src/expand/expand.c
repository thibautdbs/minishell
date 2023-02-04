/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:08:28 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/04 02:09:42 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <errno.h>//errno
#include <stddef.h>//NULL
#include <stdio.h>//perror

#include "minishell/wordlst.h"
#include "minishell/wtoklst.h"

t_wordlst	*my_expand(char const *word, t_env *env)
{
	t_wtoklst	*toks;
	t_wordlst	*args;

	errno = 0;
	toks = my_wtoklst_extract(word);
	my_expand_vars(&toks, env);
	my_expand_qtd_vars(&toks);
	my_wtoklst_concat(&toks);
	my_expand_wildcard(&toks);
	args = my_wtoklst_to_words(toks);
	my_wtoklst_del(&toks);
	if (errno != 0)
	{
		perror("minishell:");
		my_wordlst_del(&args);
		return (NULL);
	}
	return (args);
}
