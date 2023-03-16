/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:31:20 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:28:32 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strdup, ft_strlen, ft_calloc, ft_strlcpy
#include <stddef.h> // NULL, size_t

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*buf;

	size = ft_strlen(s) + 1;
	buf = (char *) ft_calloc(size, sizeof(char));
	if (buf == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(buf, s, size);
	return (buf);
}
