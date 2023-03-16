/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:03:00 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/17 19:24:13 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strlen
#include <stddef.h> // size_t, NULL

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i += 1;
	}
	return (i);
}
