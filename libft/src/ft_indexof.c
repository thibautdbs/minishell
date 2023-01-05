/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:14:59 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/24 15:48:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL, size_t
#include <sys/types.h> // ssize_t

ssize_t	ft_indexof(void const *arr, void const *ref, size_t nmemb, size_t size)
{
	char const	*buf;
	size_t		i;

	if (arr == NULL || ref == NULL)
		return (-1);
	buf = arr;
	i = 0;
	while (i < nmemb)
	{
		if (ft_memcmp(ref, buf, size) == 0)
			return (i);
		buf += size;
		i++;
	}
	return (-1);
}
