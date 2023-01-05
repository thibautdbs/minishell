/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:58:20 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 23:37:59 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

char	*ft_strtok_r(char *str, char const *sep, char **saveptr)
{
	size_t	len;
	char	*tok;

	if (saveptr == NULL || (*saveptr == NULL && str == NULL))
		return (NULL);
	if (str == NULL)
		str = *saveptr;
	tok = str + ft_strspn(str, sep);
	if (tok[0] == '\0')
	{
		*saveptr = NULL;
		return (NULL);
	}
	len = ft_strcspn(*saveptr, sep);
	if (tok[len] == '\0')
		*saveptr = NULL;
	else
		*saveptr = tok + len + 1;
	tok[len] = '\0';
	return (tok);
}
