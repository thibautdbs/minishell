/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:35:36 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/13 13:41:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <stdio.h>

#include "minishell/wordlst.h"
#include "minishell/envlst.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 2)
	{
		printf("expand: expected one and only one argument.");
		return (1);
	}

	t_wordlst	*words = my_expand(argv[1], my_envlst_init(envp));
	t_wordlst	*save = words;

	int	i = 0;
	while (words != NULL)
	{
		printf("%i:%s", i, words->content);
		words = words->next;
	}
	my_wordlst_del(&save);
	return (0);
}
