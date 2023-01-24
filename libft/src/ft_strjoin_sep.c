/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:34:23 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 12:38:49 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strjoin, ft_strlen, ft_calloc, ft_strlcpy, ft_strlcat
#include <stddef.h> // NULL, size_t

char	*ft_strjoin_sep(char const *s1, char const *s2, char const *sep)
{
	char	*buf;
	size_t	buf_size;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	buf_size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(sep) + 1;
	buf = (char *) ft_calloc(buf_size, sizeof(char));
	if (buf == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(buf, s1, buf_size);
	ft_strlcat(buf, sep, buf_size);
	ft_strlcat(buf, s2, buf_size);
	return (buf);
}
