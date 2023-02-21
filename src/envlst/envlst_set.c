/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:04:09 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 12:48:51 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <errno.h>
#include <stdio.h>//perror

#include "libft.h" //t_success

int	my_envlst_set(char const *varspec, t_envlst **penvlst)
{
	t_envlst	*new;

	errno = 0;
	new = my_envlst_new(varspec);
	if (new == NULL)
	{
		perror("minishell: Error occured when creating var");
		return (errno);
	}
	my_envlst_addback(penvlst, new);
	return (0);
}
