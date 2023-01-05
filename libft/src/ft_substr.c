/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:40:32 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 16:07:10 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

static size_t	ft_min_size(size_t a, size_t b);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	buf_size;
	size_t	s_strlen;

	if (s == NULL)
	{
		return (NULL);
	}
	s_strlen = ft_strlen(s);
	if (start >= s_strlen)
	{
		return ((char *) ft_calloc(1, sizeof(char)));
	}
	buf_size = ft_min_size(len, s_strlen - start) + 1;
	buf = (char *) ft_calloc(buf_size, sizeof(char));
	if (buf == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(buf, &s[start], buf_size);
	return (buf);
}

static size_t	ft_min_size(size_t a, size_t b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}
