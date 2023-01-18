/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:02:13 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/13 10:12:05 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redir.h"

#include <stddef.h>//NULL

#include "libft.h"//memdel

void	my_redir_destroy(t_redir **redir)
{
	t_redir	*curr;
	t_redir	*next;

	curr = *redir;
	while (curr != NULL)
	{
		next = curr->next;
		ft_memdel(&curr->label);
		ft_memdel(&curr);
		curr = next;
	}
	*redir = NULL;
}