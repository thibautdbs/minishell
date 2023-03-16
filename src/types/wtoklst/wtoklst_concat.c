/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_concat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:34:24 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/20 09:53:25 by tdubois          ###   ########.fr       */
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
	t_wtoklst	*chars;

	chars = NULL;
	while ((*ptoks) != NULL && (*ptoks)->type == CHARS)
		my_wtoklst_add_back(&chars, my_wtoklst_pop_front(ptoks));
	return (chars);
}

static	t_wtoklst	*loc_concat_word(t_wtoklst *toks)
{
	int			len;
	t_wtoklst	*word;

	len = loc_get_word_len(toks);
	word = my_wtoklst_new(CHARS, NULL, 0);
	if (word == NULL)
		return (NULL);
	word->content = malloc(len + 1);
	if (word->content == NULL)
	{
		my_wtoklst_del(&word);
		return (NULL);
	}
	word->content[0] = '\0';
	while (toks != NULL)
	{
		ft_strlcat(word->content, toks->content, len + 1);
		toks = toks->next;
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
