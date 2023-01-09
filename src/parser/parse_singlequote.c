/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_singlequote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:41:07 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/09 12:08:15 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/parser.h"

#include <stddef.h>

#include "minishell/arg.h"
#include "minishell/token.h"

t_arg	*expand_var(t_token	*toks);

t_arg *my_parse_singlequote(t_token *toks)
{
	t_arg	*arg;
	t_token	*curr;
	char	*str;
	int		len;

	len = 0;
	curr = toks->next;
	while (curr->type != SINGLEQUOTE)
	{
		len += ft_strlen(curr->content);
		curr = curr->next;
	}
	toks = toks->next;
	content = ft_calloc(len + 1, sizeof(char));
	if (content == NULL)
		return (NULL);
	while (toks->type != SINGLEQUOTE)
	{
		content = ft_strlcat(str, toks->content, len);	
		toks = toks->next;
	}
	arg = my_arg_create(str);
	if (arg == NULL)
	{
		ft_memdel(&content);
		return (NULL);
	}
	return (arg);
}

t_arg *my_parse_singlequote(t_token *toks)
{
	t_arg	*arg;
	int		len;

	if (args == NULL)
		return (NULL);
	if (toks->type != SINGLEQUOTE)
	{
		//erreur
	}
	return (arg);
}

t_arg	*my_parse_doublequote(t_token *toks)
{
	t_token	*

	while (type != DOUBLEQUOTE)
		if (WORD) ... 
		if (DOLLAR)


}



int	my_parse_join_words(t_arg **arg, t_token *toks)
{
	int		len;
	t_token	*curr;
	char	*content;

	*arg = NULL;
	len = 0;
	curr = toks;
	while (curr != NULL && curr->type == WORD)
	{
		len += ft_strlen(curr->content);
		curr = curr->next;
	}
	content = ft_calloc(len, sizeof(char));
	if (content == NULL)
		return (-1);
	*arg = my_arg_create(content);
	if (*arg == NULL)
	{
		ft_memdel(&content);
		return (-1);
	}
	return (len);
}
