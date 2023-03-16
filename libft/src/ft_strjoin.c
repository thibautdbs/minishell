/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:13:54 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:21:06 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strjoin, ft_strlen, ft_calloc, ft_strlcpy, ft_strlcat
#include <stddef.h> // NULL, size_t

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	buf_size;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	buf_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	buf = (char *) ft_calloc(buf_size, sizeof(char));
	if (buf == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(buf, s1, buf_size);
	ft_strlcat(buf, s2, buf_size);
	return (buf);
}
