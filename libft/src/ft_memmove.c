/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:04:47 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:15:09 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_memmove, ft_memcpy
#include <stddef.h> // NULL, size_t

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		((char *) dest)[n - 1 - i] = ((char *) src)[n - 1 - i];
		i += 1;
	}
	return (dest);
}
