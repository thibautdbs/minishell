/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 17:17:41 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include <unistd.h> //write
#include "libft.h" //t_success, ft_strlen, ft_strchr
#include "minishell/envlst.h"
#include "minishell/wordlst.h"

static int	loc_print_export(t_envlst *envlst);

int	my_builtin_export(t_wordlst *words, t_envlst **penvlst)
{
	int	res;

	if (words == NULL)
		return (loc_print_export(*penvlst));
	words = words->next;
	res = 0;
	while (words != NULL)
	{
		if (my_is_valid_identifier(words->content, '=') == FAILURE)
		{
			ft_puterr("minishell: export: not a valid identifier");
			res = 1;
		}
		else 
			res = my_envlst_apply(words->content, penvlst);
		if (res > 1)
			return (res);
		words = words->next;
	}
	return (res);
}

static int	loc_print_export(t_envlst *envlst)
{
	t_envlst	*curr;
	int		label_len;

	curr = envlst;
	while (envlst != NULL)
	{
		label_len = ft_strlen(curr->content)
			- ft_strlen(ft_strchr(curr->content, '='));
		ft_putstr_fd("declare -x ", STDOUT);
		write(STDOUT, curr->content, label_len);
		if (ft_strchr(curr->content, '=') != NULL)
		{
			ft_putstr_fd("=\"", STDOUT);
			ft_putstr_fd(ft_strchr(curr->content, '=') + 1, STDOUT);
			ft_putstr_fd("\"\n", STDOUT);
		}
		else
			ft_putstr_fd("\n", STDOUT);
		curr = curr->next;
	}
	return (0);
}
