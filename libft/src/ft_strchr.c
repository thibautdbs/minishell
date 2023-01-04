/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:06:41 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:32:22 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strchr, ft_strlen
#include <stddef.h> // NULL, size_t

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if ((char) c == '\0')
	{
		return ((char *) &s[ft_strlen(s)]);
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			return ((char *) &s[i]);
		}
		i += 1;
	}
	return (NULL);
}
