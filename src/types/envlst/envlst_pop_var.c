/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_pop_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:40:30 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 11:29:42 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include "libft.h"

void	my_envlst_del_var(char const *varspec, t_envlst **penvlst)
{
	int			len;
	t_envlst	*var;

	len = 0;
	while (varspec[len] != '\0')
	{
		if (ft_strncmp(varspec + len, "+=", 2) == 0)
			break ;
		if (ft_strncmp(varspec + len, "=", 1) == 0)
			break ;
		len++;
	}
	while (*penvlst != NULL)
	{
		if (len == (int) ft_strcspn((*penvlst)->content, "=")
			&& ft_strncmp((*penvlst)->content, varspec, len) == 0)
		{
			var = my_envlst_pop_front(penvlst);
			ft_memdel(&var);
			return ;
		}
		penvlst = &(*penvlst)->next;
	}
	return ;
}
