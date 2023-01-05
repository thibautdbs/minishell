/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:18:22 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/12 15:27:37 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL
#include <stdlib.h> // free

char	**ft_readlines(int fd)
{
	t_list	*line_lst;
	char	**lines;
	int		i;

	line_lst = ft_lstreadlines(fd);
	if (line_lst == NULL)
		return (NULL);
	lines = ft_calloc((size_t)ft_lstsize(line_lst) + 1, sizeof(char *));
	if (lines == NULL)
	{
		ft_lstclear(&line_lst, free);
		return (NULL);
	}
	i = 0;
	while (i < ft_lstsize(line_lst))
	{
		lines[i] = ft_lstat(line_lst, i)->content;
		i++;
	}
	ft_lstclear(&line_lst, NULL);
	lines[i] = NULL;
	return (lines);
}
