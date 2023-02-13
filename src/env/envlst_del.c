/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:02:15 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 11:39:13 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <libft.h> //ft_memset

void	my_envlst_del(t_envlst **env)
{
	t_envlst	*curr;
	t_envlst	*next;

	curr = *env;
	while (curr != NULL)
	{
		ft_memdel(&curr->content);
		next = curr->next;
		ft_memdel(&curr);
		curr = next;
	}
	*env = NULL;
}
