/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_concat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:34:24 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/03 16:18:17 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include <stddef.h>//NULL
#include <stdlib.h>//malloc

#include "libft.h"

static t_wtoklst	*loc_pop_adjacent_chars(t_wtoklst **ptoks);
static t_wtoklst	*loc_concat_word(t_wtoklst *toks);
static int			loc_get_word_len(t_wtoklst *toks);

void	my_wtoklst_concat(t_wtoklst **ptoks)
{
	t_wtoklst	*tmp;
	t_wtoklst	*word;

	while ((*ptoks) != NULL)
	{
		if ((*ptoks)->type == CHARS)
		{
			tmp = loc_pop_adjacent_chars(ptoks);
			word = loc_concat_word(tmp);
			my_wtoklst_add_front(ptoks, word);
			my_wtoklst_del(&tmp);
		}
		ptoks = &(*ptoks)->next;
	}
}

static t_wtoklst	*loc_pop_adjacent_chars(t_wtoklst **ptoks)
{
	t_wtoklst	*first_chars;
	t_wtoklst	*last_chars;

	first_chars = *ptoks;
	while ((*ptoks)->next != NULL && (*ptoks)->next->type == CHARS)
		ptoks = &(*ptoks)->next;
	last_chars = *ptoks;
	ptoks = &(*ptoks)->next;
	last_chars->next = NULL;
	return (first_chars);
}

static	t_wtoklst	*loc_concat_word(t_wtoklst *toks)
{
	int			len;
	t_wtoklst	*word;
	char		*content;

	len = loc_get_word_len(toks);
	content = malloc(len + 1);
	while (toks != NULL)
	{
		ft_strlcat(content, toks->content, len + 1);
		toks = toks->next;
	}
	word = my_wtoklst_new(CHARS, content);
	if (word == NULL)
	{
		ft_memdel(&content);
		return (NULL);
	}
	return (word);
}

static int	loc_get_word_len(t_wtoklst *toks)
{
	int	len;

	len = 0;
	while (toks != NULL)
	{
		len += ft_strlen(toks->content);
		toks = toks->next;
	}
	return (len);
}
