/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:49:20 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 11:29:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/token.h"

#include <stddef.h>//NULL

#include "libft.h"//memdel

void	my_tok_destroy(t_tok **tok)
{
	t_tok	*curr;
	t_tok	*next;

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
