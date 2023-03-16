/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:04:43 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/16 13:36:16 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>//LONG_MAX, LONG_MIN
#include <stdbool.h>

bool	ft_islong(char const *nptr)
{
	long	n;
	long	digit;
	bool	is_neg;

	if (nptr == NULL)
		return (false);
	nptr += ft_strspn(nptr, " \f\n\r\t\v");
	is_neg = (*nptr == '-');
	nptr += (ft_strspn(nptr, "+-") > 0);
	n = 0;
	while (ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (n > (LONG_MAX - digit) / 10)
			return (false);
		if (n < (LONG_MIN + digit) / 10)
			return (false);
		if (is_neg)
			n = n * 10 - digit;
		else
			n = n * 10 + digit;
		nptr++;
	}
	return (true);
}
