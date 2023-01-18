/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:04:43 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/18 14:29:08 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h> // LLONG_MAX, LLONG_MIN

t_bool	ft_islong(char const *nptr)
{
	long	n;
	long	digit;
	t_bool	is_neg;

	if (nptr == NULL)
		return (FALSE);
	nptr += ft_strspn(nptr, " ");
	is_neg = (*nptr == '-');
	nptr += (ft_strspn(nptr, "+-") > 0);
	n = 0;
	while (ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (n > (LLONG_MAX - digit) / 10)
			return (FALSE);
		if (n < (LLONG_MIN + digit) / 10)
			return (FALSE);
		if (is_neg)
			n = n * 10 - digit;
		else
			n = n * 10 + digit;
		nptr++;
	}
	return (TRUE);
}
