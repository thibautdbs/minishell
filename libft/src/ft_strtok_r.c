/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:58:20 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/20 11:16:14 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

char	*ft_strtok_r(char *str, char const *sep, char **saveptr)
{
	char	*tok;

	if (str == NULL && *saveptr == NULL)
		return (NULL);
	if (str == NULL)
		tok = *saveptr;
	else
		tok = str;
	tok += ft_strspn(tok, sep);
	if (tok[0] == '\0')
	{
		*saveptr = NULL;
		return (NULL);
	}
	*saveptr = tok + ft_strcspn(tok, sep);
	*saveptr += ft_strspn(*saveptr, sep);
	tok[ft_strcspn(tok, sep)] = '\0';
	return (tok);
}
