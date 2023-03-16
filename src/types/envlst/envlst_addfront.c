/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_addfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:34:15 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 16:46:38 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

void	my_envlst_addfront(t_envlst **penvlst, t_envlst *new)
{
	if (*penvlst != NULL)
		my_envlst_addback(&new, *penvlst);
	*penvlst = new;
}
