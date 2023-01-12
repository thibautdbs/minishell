/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:03:57 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 17:41:46 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/toks.h"

#include <stddef.h>//NULL

#include "libft.h"

t_toks	*my_toks_create(t_tok_t type, char const *str, int len)
{
	t_toks	*tok;

	tok = ft_calloc(1, sizeof(t_toks));
	if (tok == NULL)
		return (NULL);
	tok->content = ft_strndup(str, len);
	if (tok->content == NULL)
	{
		ft_memdel(&tok);
		return (NULL);
	}
	tok->type = type;
	tok->next = NULL;
	return (tok);
}
