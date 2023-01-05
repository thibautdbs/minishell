/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:36:29 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/21 23:54:37 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stddef.h> // NULL size_t

size_t	ft_strcspn(char const *str, char const *reject)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && ft_strchr(reject, str[i]) == NULL)
	{
		i++;
	}
	return (i);
}
