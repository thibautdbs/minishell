/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:55:12 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/20 02:05:08 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL
#include <stdlib.h> // malloc

void	*ft_memdup(void const *buf, size_t size)
{
	void	*bufcpy;

	if (buf == NULL || size == 0)
		return (NULL);
	bufcpy = malloc(size);
	if (bufcpy == NULL)
		return (NULL);
	ft_memcpy(bufcpy, buf, size);
	return (bufcpy);
}
