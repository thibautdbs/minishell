/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/16 10:03:41 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL

#include "libft.h" //ft_strchr, ft_puterr, ft_putstr_fd
#include "minishell/envlst.h"

int	my_builtin_unset(t_wordlst *words, t_envlst **penvlst)
{
	int	res;

	res = 0;
	while (words != NULL)
	{
		if (my_is_valid_identifier(words->content, '\0') == FAILURE)
		{
			ft_puterr_endl("minishell: unset: not a valid identifier");
			res = 1;
		}
		my_envlst_del_var(words->content, penvlst);
		words = words->next;
	}
	return (res);
}
