/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirlst_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:02:13 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/09 15:52:25 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redirlst.h"

#include <stddef.h>//NULL

void	my_redirlst_del(t_redirlst **predirlst)
{
	t_redirlst	*tmp;

	while (*predirlst != NULL)
	{
		tmp = my_redirlst_pop_front(predirlst);
		my_redirlst_del_one(&tmp);
	}
}
