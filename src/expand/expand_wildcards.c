/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:52:09 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 12:35:04 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <dirent.h>
#include <stdbool.h>
#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/env.h"
#include "minishell/wtoklst.h"

static t_wtoklst	*loc_pop_one_word(t_wtoklst **ptoks);
static bool			loc_has_wildcards(t_wtoklst *toks);
static t_wtoklst	*loc_get_matched_filenames(t_wtoklst *toks);
static bool			loc_pattern_matches(t_wtoklst *toks, char const *str);

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
		if (loc_pattern_matches(toks, file->d_name))
		{
			tmp = my_wtoklst_new(CHARS, NULL);
			if (tmp == NULL)
				break ;
			tmp->content = ft_strdup(file->d_name);
			my_wtoklst_add_back(&files, tmp);
			my_wtoklst_add_back(&files, my_wtoklst_new(BLANKS, NULL));
		}
		file = readdir(dir);
	}
	closedir(dir);
	return (files);
}

static bool	loc_pattern_matches(t_wtoklst *toks, char const *str)
{
	int	len;

	if (*str == '.' && toks->type == WILDCARD)
		return (false);
	while (toks != NULL)
	{
		if (toks->type == WILDCARD)
		{
			toks = toks->next;
			continue ;
		}
		if (*str != '\0')
			return (false);
		len = ft_strlen(toks->content);
		if (ft_strncmp(toks->content, str, len) == 0)
		{
			toks = toks->next;
			str += len;
			continue ;
		}
		str++;
	}
	return (true);
}
