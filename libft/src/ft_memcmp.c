/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:41:32 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:21:42 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_memcmp
#include <stddef.h> // size_t

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *) s1)[i] != ((char *) s2)[i])
		{
			return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
		}
		i += 1;
	}
	return (0);
}
