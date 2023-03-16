/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:19:53 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:24:05 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strlcpy, ft_strlen
#include <stddef.h> // size_t

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
