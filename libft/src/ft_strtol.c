/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:56:20 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/16 16:18:36 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>//LONG_MAX, LONG_MIN
#include <errno.h>

long	ft_strtol(char const *nptr, char **endptr, int *errptr)
{
	long	n;
	long	digit;
	bool	is_neg;

	nptr += ft_strspn(nptr, " \f\n\r\t\v");
	is_neg = (*nptr == '-');
	nptr += (ft_strspn(nptr, "+-") > 0);
	n = 0;
	while (ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (n < (LONG_MIN + digit) / 10 || (LONG_MAX - digit) / 10 < n)
		{
			*errptr = ERANGE;
			if (is_neg)
				return (LONG_MIN);
			return (LONG_MAX);
		}
		n = n * 10 + (1 - 2 * is_neg) * digit;
		nptr++;
	}
	*errptr = 0;
	if (endptr != NULL)
		*endptr = (char *) nptr;
	return (n);
}
