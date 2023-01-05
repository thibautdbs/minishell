/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:16:49 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:12:34 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_split, ft_calloc, ft_substr
#include <stdlib.h> // free
#include <stddef.h> // NULL

static size_t	ft_strchrspn(char const *s, char accept)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] == accept)
	{
		i += 1;
	}
	return (i);
}

static size_t	ft_strchrcspn(char const *s, char reject)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != reject)
	{
		i += 1;
	}
	return (i);
}

static size_t	ft_tokcount(char const *s, char c)
{
	size_t	i;
	size_t	word_count;

	word_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		i += ft_strchrspn(&s[i], c);
		if (s[i] != '\0' && s[i] != c)
		{
			word_count += 1;
		}
		i += ft_strchrcspn(&s[i], c);
	}
	return (word_count);
}

static void	ft_del_toks(char ***tokens)
{
	size_t	i;

	i = 0;
	while ((*tokens)[i] != NULL)
	{
		free(*(tokens)[i]);
		i += 1;
	}
	free(*tokens);
	*tokens = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tokens;
	size_t	i;
	size_t	tok_len;
	size_t	tokcount;

	if (s == NULL)
	{
		return (NULL);
	}
	tokcount = ft_tokcount(s, c);
	tokens = (char **) ft_calloc(tokcount + 1, sizeof(char *));
	i = 0;
	while (tokens != NULL && i < tokcount)
	{
		s += ft_strchrspn(s, c);
		tok_len = ft_strchrcspn(s, c);
		tokens[i] = ft_substr(s, 0, tok_len);
		s += tok_len;
		if (tokens[i] == NULL)
		{
			ft_del_toks(&tokens);
		}
		i += 1;
	}
	return (tokens);
}
