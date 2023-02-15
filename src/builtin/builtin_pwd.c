/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 18:23:25 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include "libft.h" //ft_putstr_fd, ft_memdel

#include "minishell/envlst.h"

int	my_builtin_pwd(void)
{
	char	*pwd;

	pwd = my_get_pwd();
	if (pwd == NULL)
		return (12);
	ft_putstr_fd(pwd, STDOUT);
	ft_putstr_fd("\n", STDOUT);
	ft_memdel(&pwd);
	return (0);
}
