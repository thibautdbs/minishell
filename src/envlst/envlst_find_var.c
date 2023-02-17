/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_find_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:56:28 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/17 16:41:21 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <stddef.h> //NULL

#include "libft.h" //ft_strncmp

/**
 * Search a node in envlst whose content match varspec until +=, =, or EOF.
 */
t_envlst	*my_envlst_find_var(char const *varspec, t_envlst *envlst)
{
	int	len;

	len = 0;
	while (varspec[len] != '\0')
	{
		if (ft_strncmp(varspec, "+=", 2))
			break ;
		if (ft_strncmp(varspec, "=", 1))
			break ;
		len++;
	}
	while (envlst != NULL)
	{
		if (len == (int) ft_strcspn(envlst->content, "=")
				&& ft_strncmp(envlst->content, varspec, len))
			return (envlst);
		envlst = envlst->next;
	}
	return (NULL);
}
