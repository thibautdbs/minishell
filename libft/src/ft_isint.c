/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:41:22 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/17 16:40:14 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h> // INT_MAX, INT_MIN

t_bool	ft_isint(char const *nptr)
{
	int		n;
	int		digit;
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
		if (n > (INT_MAX - digit) / 10)
			return (FALSE);
		if (n < (INT_MIN + digit) / 10)
			return (FALSE);
		if (is_neg)
			n = n * 10 - digit;
		else
			n = n * 10 + digit;
		nptr++;
	}
	return (TRUE);
}
