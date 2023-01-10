/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_pop_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:04:49 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/05 16:57:36 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/token.h"

#include <stddef.h>//NULL

#include "libft.h"//memdel

void	my_tok_pop_back(t_token **toks)
{
	if (*toks == NULL)
		return ;
	my_tok_at(*toks, -2)->next = NULL;
}
