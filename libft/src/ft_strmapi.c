/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:02:49 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/10 11:28:03 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strmapi, ft_calloc, ft_strlen
#include <stddef.h> // NULL, size_t

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*buf;

	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	buf = (char *) ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (buf == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		buf[i] = (*f)(i, s[i]);
		i += 1;
	}
	buf[i] = '\0';
	return (buf);
}
