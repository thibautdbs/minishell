/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:10:23 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 13:06:31 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <stddef.h> //NULL
#include <stdlib.h>//malloc

#include "libft.h" //ft_strdup

static void	loc_remove_first_plus(char *dest, char const *varspec);

t_envlst	*my_envlst_new(char const *varspec)
{
	t_envlst	*env;

	env = ft_calloc(1, sizeof(t_envlst));
	if (env == NULL)
		return (NULL);
	if (varspec == NULL)
		return (env);
	env->content = malloc(ft_strlen(varspec) + 1);
	if (env->content == NULL)
	{
		ft_memdel(&env);
		return (NULL);
	}
	loc_remove_first_plus(env->content, varspec);
	return (env);
}

static void	loc_remove_first_plus(char *dest, char const *varspec)
{
	int	i;
	int	j;

	i = 0;
	while (varspec[i] != '+' && varspec[i] != '=' && varspec[i] != '\0')
	{
		dest[i] = varspec[i];
		i++;
	}
	if (varspec[i] == '\0')
		return ;
	j = (varspec[i] == '+');
	while (varspec[i + j] != '\0')
	{
		dest[i] = varspec[i + j];
		i++;
	}
	dest[i] = '\0';
}
