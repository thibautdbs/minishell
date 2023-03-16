/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:01:45 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/16 11:54:27 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include "libft.h"

t_wtoklst	*my_wtoklst_new(t_wtoklst_t type, char const *content, int len)
{
	t_wtoklst	*tok;

	tok = ft_calloc(1, sizeof(t_wtoklst));
	if (tok == NULL)
		return (NULL);
	tok->type = type;
	tok->next = NULL;
	if (content == NULL)
		return (tok);
	tok->content = ft_substr(content, 0, len);
	if (tok->content == NULL)
	{
		ft_memdel(&tok);
		return (NULL);
	}
	return (tok);
}
