/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:34:58 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/29 17:35:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

char	*ft_strndup(char const *s, size_t n)
{
	size_t	size;
	char	*buf;

	size = ft_strlen(s) + 1;
	if (size > n + 1)
	{
		size = n + 1;
	}
	buf = (char *) malloc(size * sizeof(char));
	if (buf == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(buf, s, size);
	return (buf);
}
