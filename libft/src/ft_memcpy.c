/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:55:46 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/19 14:58:44 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL, size_t

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		((char *) dest)[i] = ((char *) src)[i];
		i += 1;
	}
	return (dest);
}
