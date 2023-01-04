/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:51:28 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 16:03:23 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL, size_t

static size_t	ft_min_size(size_t a, size_t b);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t const	little_strlen = ft_strlen(little);

	if (little_strlen == 0)
	{
		return ((char *) big);
	}
	if (len == 0)
	{
		return (NULL);
	}
	i = 0;
	while (i + little_strlen <= ft_min_size(len, ft_strlen(big)))
	{
		if (ft_strncmp(&big[i], little, little_strlen) == 0)
		{
			return ((char *) &(big[i]));
		}
		i += 1;
	}
	return (NULL);
}

static size_t	ft_min_size(size_t a, size_t b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}
