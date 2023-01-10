/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:18:29 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/06 11:21:50 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsdel(char ***strs)
{
	int	i;

	if (*strs == NULL)
		return ;
	i = 0;
	while ((*strs)[i] != NULL)
	{
		ft_memdel(&(*strs)[i]);
		i++;
	}
	ft_memdel(strs);
}
