/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:37:14 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:28:48 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_calloc, ft_bzero
#include <limits.h> // INT_MAX
#include <stdlib.h> // malloc
#include <stddef.h> // NULL, size_t

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;

	if (size != 0 && INT_MAX / size < nmemb)
	{
		return (NULL);
	}
	buf = malloc(nmemb * size);
	if (buf == NULL)
	{
		return (NULL);
	}
	ft_bzero(buf, nmemb * size);
	return (buf);
}
