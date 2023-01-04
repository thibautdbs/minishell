/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:32:33 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/04 14:10:47 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "minishell/token.h"
#include <stdio.h>

#define DEBUG

void	dev_print_one_token(t_token const *tok)
{
	char const	*token_types[] = {"PIPE", "AND", "LEFTPAR", "RIGHTPAR",
		"DOUBLEQUOTE", "SINGLEQUOTE", "LEFTAGBRACKET", "RIGHTAGBRACKET",
		"SPACES", "WORD"};

	printf("Token type : %s\n", token_types[tok->type]);
	printf("Token content : \"%s\"\n", tok->content);
	printf("Token next : %p\n\n", tok->next);
}

void	dev_print_token(t_token const *tok)
{
#ifdef DEBUG
	t_token const	*current;
	int				index;

	current = tok;
	index = 0;
	while (current)
	{
		printf("\033[0;33m----TOKEN %d----\033[0m\n", index);
		dev_print_one_token(current);
		index++;
		current = current->next;
	}
#else
	(void) tok;
#endif
}
