/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:13:03 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/24 16:41:49 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"

#include <stddef.h>//NULL

#include "libft.h"

t_subshell	*my_subshell_create(void)
{
	t_subshell	*subshell;

	subshell = ft_calloc(1, sizeof(t_subshell));
	if (subshell == NULL)
		return (NULL);
	subshell->cmd = NULL;
	subshell->redirs = NULL;
	return (subshell);
}
