/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:17:59 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/17 13:25:36 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
		}
		i += 1;
	}
	return (0);
}
