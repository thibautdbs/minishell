/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:32:27 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:15:22 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_striteri
#include <stddef.h> // NULL, size_t

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL)
	{
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i += 1;
	}
}
