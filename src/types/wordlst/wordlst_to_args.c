/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlst_to_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:38:51 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 09:32:20 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wordlst.h"

#include "libft.h" //ft_strsdel, ft_strdup, ft_calloc

char	**my_wordlst_to_args(t_wordlst *wordlst)
{
	char	**argv;
	int		i;

	argv = ft_calloc(my_wordlst_size(wordlst) + 1, sizeof(char *));
	if (argv == NULL)
		return (NULL);
	i = 0;
	while (wordlst != NULL)
	{
		argv[i] = ft_strdup(wordlst->content);
		if (argv[i] == NULL)
		{
			ft_strsdel(&argv);
			return (NULL);
		}
		wordlst = wordlst->next;
		i++;
	}
	return (argv);
}
