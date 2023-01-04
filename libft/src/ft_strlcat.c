/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:46:37 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:14:56 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// ft_strlcat, ft_strlen, ft_strlcpy
#include <stddef.h> // NULL, size_t

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_orig_strlen;

	if (dst == NULL && size == 0)
	{
		return (ft_strlen(src));
	}
	dst_orig_strlen = ft_strlen(dst);
	if (size == 0 || size < dst_orig_strlen)
	{
		return (size + ft_strlen(src));
	}
	ft_strlcpy(&dst[dst_orig_strlen], src, size - dst_orig_strlen);
	return (dst_orig_strlen + ft_strlen(src));
}
