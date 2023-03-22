/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:31:46 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/22 12:10:19 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/tok.h"
#include "minishell/wordlst.h"

#define UNMATCHED_QUOTE -1

static int	loc_get_wordcontent_len(char const *str);

int	my_parse_word(char const **pstr, t_wordlst **ret_wordlst)
{
	int			len;

	my_tok_skip_blanks(pstr);
	len = loc_get_wordcontent_len(*pstr);
	if (len == UNMATCHED_QUOTE)
	{
		*ret_wordlst = NULL;
		*pstr += ft_strlen(*pstr);
		return (LEX_ERR);
	}
	*ret_wordlst = my_wordlst_new();
	if (*ret_wordlst == NULL)
		return (ENOMEM);
	(*ret_wordlst)->content = ft_substr(*pstr, 0, len);
	*pstr += len;
	if ((*ret_wordlst)->content == NULL)
	{
		my_wordlst_del(ret_wordlst);
		return (ENOMEM);
	}
	return (EXIT_SUCCESS);
}

static int	loc_get_wordcontent_len(char const *str)
{
	int		len;
	char	quote[2];

	len = 0;
	quote[1] = '\0';
	while (!my_tok_is_blank(str + len) && my_tok_type(str + len) == WORD)
	{
		if (str[len] == '\"' || str[len] == '\'')
		{
			quote[0] = str[len];
			len += 1 + ft_strcspn(str + len + 1, quote);
			if (str[len] == '\0')
			{
				ft_puterr("minishell: unexpected EOF while looking ");
				ft_puterr("for matching `");
				ft_putchar_fd(quote[0], STDERR_FILENO);
				ft_puterr_endl("'");
				return (UNMATCHED_QUOTE);
			}
			len += 1;
		}
		else
			len++;
	}
	return (len);
}
