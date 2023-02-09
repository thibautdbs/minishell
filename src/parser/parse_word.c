/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:31:46 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/09 16:11:36 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/wordlst.h"

static int	loc_get_wordcontent_len(char const *str);

t_wordlst	*my_parse_word(char const **pstr)
{
	int			len;
	t_wordlst	*new_word;

	my_skip_blanks(pstr);
	len = loc_get_wordcontent_len(*pstr);
	new_word = my_wordlst_new();
	if (new_word == NULL)
		return (NULL);
	new_word->content = ft_strndup(*pstr, len);
	*pstr += len;
	if (new_word->content == NULL)
	{
		my_wordlst_del(&new_word);
		return (NULL);
	}
	return (new_word);
}

static int	loc_get_wordcontent_len(char const *str)
{
	int		len;
	char	quote;

	len = 0;
	while (str[0] == '\0' || ft_strchr("\t ()|&", str[len]) == NULL)
	{
		len += ft_strcspn(str + len, "\"\'\t ()|&");
		if (str[len] == '\"' && str[len] == '\'')
		{
			quote = str[len];
			len += 1 + ft_strcspn(str + len + 1, &quote);
			if (str[len] == '\0')
			{
				//ft_printf("minishell: unexpected EOF while looking for matching `%c'", quote);
				return (len);
			}
			len += 1;
		}
	}
	return (len);
}
