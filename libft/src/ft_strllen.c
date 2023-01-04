/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strllen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:29:43 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/08 10:34:57 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strllen
#include <stddef.h> // size_t

size_t	ft_strllen(char const *str, size_t size)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && i < size)
	{
		i += 1;
	}
	return (i);
}
