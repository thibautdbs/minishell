/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:56:37 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/20 17:02:05 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include <unistd.h> //getcwd
#include "libft.h" //ft_calloc, ft_puterr, ft_memdel

#include "minishell/env.h"

char	*my_get_pwd(void)
{
	char	*buf;
	int		size;

	size = 1;
	while (1)
	{
		buf = ft_calloc(sizeof(char), size);
		if (buf == NULL)
		{
			ft_puterr("malloc error when creating pwd buf");
			return (NULL);
		}
		if (getcwd(buf, size) != NULL)
			break ;
		ft_memdel(&buf);
		size++;
	}
	return (buf);
}
