/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/16 12:55:13 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include <stdbool.h>

#include "libft.h" //ft_putstr_fd, ft_putendl_fd
#include "minishell/wordlst.h"

static bool	loc_is_n_opt(char *str);

int	my_builtin_echo(t_wordlst *words)
{
	bool	n_opt;

	n_opt = false;
	if (words != NULL && loc_is_n_opt(words->content))
		n_opt = true;
	while (words != NULL && loc_is_n_opt(words->content))
		words = words->next;
	while (words != NULL)
	{
		ft_putstr_fd(words->content, STDOUT);
		words = words->next;
		if (words != NULL)
			ft_putstr_fd(" ", STDOUT);
	}
	if (n_opt)
		ft_putendl_fd("", STDOUT);
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
