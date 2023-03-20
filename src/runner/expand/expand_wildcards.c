/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:52:09 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/20 11:10:00 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <dirent.h>
#include <stdbool.h>
#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/wtoklst.h"

static t_wtoklst	*loc_pop_one_word(t_wtoklst **ptoks);
static bool			loc_has_wildcards(t_wtoklst *toks);
static t_wtoklst	*loc_get_matched_filenames(t_wtoklst *toks);
// static t_wtoklst	*loc_sort_wtoks(t_wtoklst *wtoklst);
static void			loc_insert_sorted(t_wtoklst *new, t_wtoklst **pfiles);

void	my_expand_wildcards(t_wtoklst **ptoks)
{
	t_wtoklst	*tmp;
	t_wtoklst	*files;

	while ((*ptoks) != NULL)
	{
		if ((*ptoks)->type != BLANKS)
		{
			tmp = loc_pop_one_word(ptoks);
			files = NULL;
			if (loc_has_wildcards(tmp))
				files = loc_get_matched_filenames(tmp);
			if (files == NULL)
				files = tmp;
			else
				my_wtoklst_del(&tmp);
			my_wtoklst_convert(files, WILDCARD, CHARS);
			my_wtoklst_add_front(ptoks, files);
		}
		ptoks = &(*ptoks)->next;
	}
}

static t_wtoklst	*loc_pop_one_word(t_wtoklst **ptoks)
{
	t_wtoklst	*word;

	word = NULL;
	while (*ptoks != NULL && (*ptoks)->type != BLANKS)
		my_wtoklst_add_back(&word, my_wtoklst_pop_front(ptoks));
	return (word);
}

static bool	loc_has_wildcards(t_wtoklst *toks)
{
	while (toks != NULL)
	{
		if (toks->type == WILDCARD)
			return (true);
		toks = toks->next;
	}
	return (false);
}

static t_wtoklst	*loc_get_matched_filenames(t_wtoklst *toks)
{
	t_wtoklst		*files;
	DIR				*dir;
	struct dirent	*file;
	t_wtoklst		*tmp;

	files = NULL;
	dir = opendir(".");
	if (dir == NULL)
		return (NULL);
	file = readdir(dir);
	while (file != NULL)
	{
		if (my_pattern_match(toks, file->d_name))
		{
			tmp = my_wtoklst_new(CHARS, file->d_name, ft_strlen(file->d_name));
			if (tmp == NULL)
				break ;
			loc_insert_sorted(tmp, &files);
		}
		file = readdir(dir);
	}
	closedir(dir);
	return (files);
}

static void	loc_insert_sorted(t_wtoklst *new, t_wtoklst **pfiles)
{
	while (*pfiles != NULL)
	{
		if ((*pfiles)->type == BLANKS)
			pfiles = &(*pfiles)->next;
		else if (ft_strcmp((*pfiles)->content, new->content) < 0)
			pfiles = &(*pfiles)->next;
		else
			break ;
	}
	my_wtoklst_add_front(pfiles, my_wtoklst_new(BLANKS, NULL, 0));
	my_wtoklst_add_front(pfiles, new);
}
