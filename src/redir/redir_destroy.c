/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:02:13 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/09 15:17:45 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redir.h"

#include <stddef.h>//NULL

#include "libft.h"//memdel
#include "minishell/arg.h"//my_arg_destroy

void	my_redir_destroy(t_token **redir)
{
	t_token	*curr;
	t_token	*next;

	curr = *redir;
	while (curr != NULL)
	{
		next = curr->next;
		my_arg_destroy(&(*redir)->arg);
		ft_memdel(&curr);
		curr = next;
	}
	*redir = NULL;
}
