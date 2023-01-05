/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:22:54 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/21 23:55:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL size_t

size_t	ft_strspn(char const *str, char const *accept)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && ft_strchr(accept, str[i]) != NULL)
	{
		i++;
	}
	return (i);
}
