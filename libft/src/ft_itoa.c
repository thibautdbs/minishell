/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:45:25 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 21:52:55 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL, size_t

static int		ft_has_twodigits(int n);
static size_t	ft_nptrlen(int n);

char	*ft_itoa(int n)
{
	size_t			i;
	char			*buf;
	size_t const	nptrlen = ft_nptrlen(n);

	buf = (char *) ft_calloc(nptrlen + 1, sizeof(char));
	if (buf == NULL)
	{
		return (NULL);
	}
	if (n < 0)
	{
		buf[0] = '-';
	}
	i = nptrlen - 1;
	while (ft_has_twodigits(n))
	{
		buf[i] = ft_tochar(ft_abs(n % 10));
		n = n / 10;
		i -= 1;
	}
	buf[i] = ft_tochar(ft_abs(n % 10));
	return (buf);
}

static int	ft_has_twodigits(int n)
{
	return (n / 10 != 0);
}

static size_t	ft_nptrlen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len += 1;
	}
	while (ft_has_twodigits(n))
	{
		n = n / 10;
		len += 1;
	}
	return (len);
}
