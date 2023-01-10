/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:06:08 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 16:35:24 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/token.h"

#include <stddef.h>//size_t,NULL

#include "libft.h"
#include "minishell/lexer.h"

t_tok	*my_tok_create(t_token_t type, char const *input, int len)
{
	t_tok	*token;

	token = ft_calloc(1, sizeof(t_tok));
	if (token == NULL)
		return (NULL);
	token->content = ft_strndup(input, len);
	if (token->content == NULL)
	{
		ft_memdel(&token);
		return (NULL);
	}
	token->type = type;
	token->next = NULL;
	return (token);
}