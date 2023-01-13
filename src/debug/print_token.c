/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:32:33 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/13 13:37:49 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

#include <stdio.h>

#include "minishell/toks.h"

static char const	*token_types[] = {
	"LPAR",
	"RPAR", 
	"AND", 
	"OR",
	"PIPE", 
	"VAR", 
	"QTD_VAR",
	"INFILE",
	"OUTFILE", 
	"APPNDFILE",
	"WILDCARD",
	"HEREDOC",
	"BLANKS",
	"WORD"
};


void	dev_print_one_token(t_toks const *tok)
{
	printf("Token type : %s\n", token_types[tok->type]);
	printf("Token content : \"%s\"\n", tok->content);
	printf("Token next : %p\n\n", tok->next);
}

void	dev_print_token(t_toks const *toks)
{
#ifdef DEBUG
	int	index;

	index = 0;
	while (toks != NULL)
	{
		printf(YELLOW"----TOKEN %d----"NC, index);
		dev_print_one_token(toks);
		index++;
		toks = toks->next;
	}
#else
	(void) tok;
#endif
}
