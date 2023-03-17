/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/17 12:59:34 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include <unistd.h> //write
#include <errno.h>

#include "libft.h" //t_success, ft_strlen, ft_strchr
#include "minishell/envlst.h"
#include "minishell/wordlst.h"

static int	loc_print_export(t_envlst *envlst);

int	my_builtin_export(t_wordlst *words, t_envlst **penvlst)
{
	int	res;

	if (my_wordlst_size(words) == 1)
		return (loc_print_export(*penvlst));
	words = words->next;
	res = 0;
	while (words != NULL)
	{
		if (my_is_valid_identifier(words->content, '=') == FAILURE)
		{
			ft_puterr("minishell: export: `");
			ft_puterr(words->content);
			ft_puterr_endl("': not a valid identifier");
			res = 1;
		}
		else if (my_envlst_apply (words->content, penvlst) != 0)
			return (errno);
		words = words->next;
	}
	return (res);
}

static int	loc_print_export(t_envlst *envlst)
{
	int		label_len;

	while (envlst != NULL)
	{
		label_len = ft_strcspn(envlst->content, "=");
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		write(STDOUT_FILENO, envlst->content, label_len);
		if (ft_strchr(envlst->content, '=') != NULL)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(ft_strchr(envlst->content, '=') + 1, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		envlst = envlst->next;
	}
	return (0);
}
