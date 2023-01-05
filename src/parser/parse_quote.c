/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:41:29 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 13:42:53 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parse.h"

#include "minishell/token.h"

/**
 *	switch types tokens surrounded by quotes to word
 */
t_token	*my_parse_quote(t_token *toks);
