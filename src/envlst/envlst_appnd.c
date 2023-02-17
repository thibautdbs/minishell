/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_appnd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:40:43 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 16:47:25 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //t_success
#include "minishell/envlst.h"

t_success	my_envlst_appnd(char *var, t_envlst **penvlst)
{
	char	*new_content;

	new_content = ft_strjoin((*penvlst)->content, ft_strchr(var, '=') + 1);
	if (new_content == NULL)
	{
		ft_puterr("error occured when appening env var");
		return (FAILURE);
	}
	ft_memdel(&(*penvlst)->content);
	(*penvlst)->content = new_content;
	return (SUCCESS);
}
