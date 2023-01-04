/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadlines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:47:01 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/12 08:47:57 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL
#include <stdlib.h> // free

t_list	*ft_lstreadlines(int fd)
{
	t_list	*lines;
	t_list	*node;
	char	*line;

	lines = NULL;
	while (1)
	{
		line = ft_gnl(fd);
		if (line == NULL)
			break ;
		node = ft_lstnew(line);
		if (node == NULL)
		{
			free(line);
			ft_lstclear(&lines, free);
			return (NULL);
		}
		ft_lstadd_back(&lines, node);
	}
	return (lines);
}
