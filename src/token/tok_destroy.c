/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:49:20 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/05 08:08:49 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/token.h"

#include <stddef.h>//NULL

#include "libft.h"//memdel

void	my_tok_destroy(t_token **tok)
{
	t_token	*curr;
	t_token	*next;

	curr = *tok;
	while (curr != NULL)
	{
		next = curr->next;
		ft_memdel(&curr->content);
		ft_memdel(&curr);
		curr = next;
	}
	*tok = NULL;
}
