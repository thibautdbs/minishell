/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_2arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:15:47 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:29:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/token.h"

#include <stddef.h>//NULL,size_t

#include "libft.h"//calloc

t_tok	**my_tok_2arr(t_tok *toks)
{
	t_tok	**arr;
	size_t	i;

	arr = ft_calloc(my_tok_size(toks), sizeof(t_tok *));
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
