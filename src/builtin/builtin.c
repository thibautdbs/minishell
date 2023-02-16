/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:29:35 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/16 10:25:06 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include "libft.h" //ft_strcmp
#include <errno.h> //errno
#include <stdio.h> //NULL

#include "minishell/wordlst.h"

int	my_builtin(t_wordlst *words, t_envlst *penvlst)
{
	char	**args;

	errno = 0;
	args = my_wordlst_to_args(words);
	if (args == NULL)
		return (errno);
	if (ft_strcmp(args[0], "cd") == 0)
		return (my_builtin_cd(args, penvlst));
	if (ft_strcmp(args[0], "echo") == 0)
		return (my_builtin_echo(args));
	if (ft_strcmp(args[0], "env") == 0)
		return (my_builtin_env(args, penvlst));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (my_builtin_pwd());
	if (ft_strcmp(args[0], "export") == 0)
		return (my_builtin_export(args, penvlst));
	if (ft_strcmp(args[0], "unset") == 0)
		return (my_builtin_unset(args, penvlst));
	return (my_builtin_exit(args));
}
