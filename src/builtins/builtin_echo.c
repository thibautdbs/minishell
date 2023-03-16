/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/16 11:52:38 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include <unistd.h>
#include <stdbool.h>

#include "libft.h" //ft_putstr_fd, ft_putendl_fd
#include "minishell/wordlst.h"

static bool	loc_is_n_opt(char *str);

int	my_builtin_echo(t_wordlst *words)
{
	bool	n_opt;

	n_opt = false;
	words = words->next;
	if (words != NULL && loc_is_n_opt(words->content))
		n_opt = true;
	while (words != NULL && loc_is_n_opt(words->content))
		words = words->next;
	while (words != NULL)
	{
		ft_putstr_fd(words->content, STDOUT_FILENO);
		words = words->next;
		if (words != NULL)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (!n_opt)
		ft_putendl_fd("", STDOUT_FILENO);
	return (0);
}

static bool	loc_is_n_opt(char *str)
{
	if (ft_strncmp(str, "-n", 2) != 0)
		return (false);
	str += 2;
	str += ft_strspn(str, "n");
	if (str[0] != '\0')
		return (false);
	return (true);
}
