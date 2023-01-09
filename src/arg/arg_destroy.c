/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:09:09 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/09 15:15:42 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/arg.h"

#include <stddef.h>//NULL

#include "libft.h"//memdel

void	my_arg_destroy(t_token **arg)
{
	t_token	*curr;
	t_token	*next;

	curr = *arg_destroy;
	while (curr != NULL)
	{
		next = curr->next;
		ft_memdel(&curr->arg);
		ft_memdel(&curr);
		curr = next;
	}
	*arg = NULL;
}
