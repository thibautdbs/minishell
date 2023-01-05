/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_2arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:15:47 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 14:29:29 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/token.h"

#include <stddef.h>//NULL,size_t

#include "libft.h"//calloc

t_token	**my_tok_2arr(t_token *toks)
{
	t_token	**arr;
	size_t	i;

	arr = ft_calloc(my_tok_size(toks), sizeof(t_token *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (toks != NULL)
	{
		arr[i] = toks;
		toks = toks->next;
		i++;
	}
	return (arr);
}
