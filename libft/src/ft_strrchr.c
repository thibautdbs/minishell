/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:12:46 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:16:44 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strrchr, ft_strlen
#include <stddef.h> // NULL, size_t

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	size_t const	s_strlen = ft_strlen(s);

	if ((char) c == '\0')
	{
		return ((char *) &s[s_strlen]);
	}
	i = 0;
	while (i < s_strlen)
	{
		if (s[s_strlen - 1 - i] == (char) c)
		{
			return ((char *) &s[s_strlen - 1 - i]);
		}
		i += 1;
	}
	return (NULL);
}
