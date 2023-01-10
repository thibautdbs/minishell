/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_pop_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:44 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/05 16:58:00 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/token.h"

#include <stddef.h>//NULL

#include "libft.h"//memdel

void	my_tok_pop_front(t_token **toks)
{
	if (*toks == NULL)
		return ;
	*toks = (*toks)->next;
}
