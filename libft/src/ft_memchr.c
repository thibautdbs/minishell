/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:23:39 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:31:10 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_memchr
#include <stddef.h> // NULL, size_t

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == (unsigned char) c)
		{
			return ((void *)s + i);
		}
		i += 1;
	}
	return (NULL);
}
