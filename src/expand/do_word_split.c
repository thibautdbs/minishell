/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_word_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:14:31 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/04 02:04:44 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/wtoklst.h"

static void	loc_skip_ifs_spaces(char const **pword, char const *sep);

t_wtoklst	*my_do_word_split(char const *word, char const *sep)
{
	t_wtoklst	*toks;
	int			len;

	toks = NULL;
	if (ft_strchr(sep, *word) != NULL)
	{
		loc_skip_ifs_spaces(&word, sep);
		if (ft_strchr(sep, *word) == NULL)
			my_wtoklst_add_back(&toks, my_wtoklst_new(BLANKS, NULL));
	}
	while (*word != '\0')
	{
		len = ft_strcspn(word, sep);
		my_wtoklst_add_back(&toks, my_wtoklst_new(CHARS, ft_strndup(word, len)));
		word += len;
		if (*word != '\0')
		{
			loc_skip_ifs_spaces(&word, sep);
			word += (ft_strchr(sep, *word) != NULL);
			loc_skip_ifs_spaces(&word, sep);
			my_wtoklst_add_back(&toks, my_wtoklst_new(BLANKS, NULL));
		}
	}
	return (toks);
}

static void	loc_skip_ifs_spaces(char const **pword, char const *sep)
{
	while (**pword != '\0')
	{
		if (ft_strchr(sep, **pword) == NULL)
			return ;
		if (ft_strchr(" \t\n", **pword) == NULL)
			return ;
		(*pword)++;
	}
}
