/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:22:46 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/07 16:45:09 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_atoi, ft_strchr, ft_isdigit
#include <stddef.h> // NULL
#include <limits.h> // LONG_MAX, LONG_MIN

static long		ft_tolong(char c);
static int		ft_sign(const char *nptr);

static long	ft_tolong(char c)
{
	return (c - '0');
}

static int	ft_sign(const char *nptr)
{
	if (nptr[0] == '-')
	{
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		i;
	long	n;

	nptr += ft_strspn(nptr, " \f\n\r\t\v");
	sign = ft_sign(nptr);
	if (nptr[0] == '+' || nptr[0] == '-')
		nptr += 1;
	i = 0;
	n = 0;
	while (ft_isdigit(nptr[i]))
	{
		if (n > (LONG_MAX - ft_tolong(nptr[i])) / 10)
		{
			if (sign == 1)
			{
				return ((int) LONG_MAX);
			}
			return ((int) LONG_MIN);
		}
		n = n * 10 + ft_tolong(nptr[i]);
		i += 1;
	}
	return ((int) sign * n);
}
