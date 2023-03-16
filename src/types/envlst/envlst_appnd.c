/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_appnd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:40:43 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 12:43:55 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <errno.h>
#include <stdio.h>//perror
#include <stddef.h>//NULL

#include "libft.h"//ft_strjoin

int	my_envlst_appnd(char const *varspec, t_envlst **penvlst)
{
	int			res;
	char		*new_varspec;
	t_envlst	*var;

	var = my_envlst_find_var(varspec, *penvlst);
	errno = 0;
	new_varspec = ft_strjoin(var->content, ft_strchr(varspec, '=') + 1);
	if (new_varspec == NULL)
	{
		perror("minishell: Error occured when appening env var");
		return (errno);
	}
	my_envlst_del_var(varspec, penvlst);
	res = my_envlst_set(new_varspec, penvlst);
	ft_memdel(&new_varspec);
	return (res);
}
