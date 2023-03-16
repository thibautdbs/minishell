/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:22:45 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:30:18 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strtrim, ft_strchr, ft_calloc, ft_strlen, ft_substr
#include <stddef.h> // NULL, size_t

static int	ft_is_inset(char c, char const *set);

static int	ft_is_inset(char c, char const *set)
{
	return (ft_strchr(set, c) != NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
	start = 0;
	while (s1[start] != '\0' && ft_is_inset(s1[start], set))
	{
		start += 1;
	}
	if (s1[start] == '\0')
	{
		return ((char *) ft_calloc(1, sizeof(char)));
	}
	end = ft_strlen(s1) - 1;
	while (start < end && ft_is_inset(s1[end], set))
	{
		end -= 1;
	}
	return (ft_substr(s1, start, end - start + 1));
}
