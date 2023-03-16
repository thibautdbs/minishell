/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:29:35 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/14 12:14:54 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include "libft.h" //ft_strcmp
#include <errno.h> //errno
#include <stdio.h> //NULL

#include "minishell/wordlst.h"

int	my_builtin(t_wordlst *words, t_envlst **penvlst, int res)
{
	if (ft_strcmp(words->content, "cd") == 0)
		return (my_builtin_cd(words, penvlst));
	if (ft_strcmp(words->content, "echo") == 0)
		return (my_builtin_echo(words));
	if (ft_strcmp(words->content, "env") == 0)
		return (my_builtin_env(words, *penvlst));
	if (ft_strcmp(words->content, "pwd") == 0)
		return (my_builtin_pwd());
	if (ft_strcmp(words->content, "export") == 0)
		return (my_builtin_export(words, penvlst));
	if (ft_strcmp(words->content, "unset") == 0)
		return (my_builtin_unset(words, penvlst));
	return (my_builtin_exit(words, res));
}
