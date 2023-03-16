/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:08:13 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/10 00:15:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>//size_t

/** ft_sitoa:
 *   Convert n into a string and stores it into str.
 *   returns len of str if it fits, and -1 otherwise.
 */
int	ft_sitoa(char *str, int const value, size_t const size)
{
	size_t	i;
	int		n;

	n = value;
	i = 0;
	while (i < size - 1 && n != 0)
	{
		str[i] = ft_abs(n % 10) + '0';
		n /= 10;
		i++;
	}
	if (i < size - 1 && value == 0)
		str[i++] = '0';
	if (i < size - 1 && value < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	if (n != 0)
		return (-1);
	return (i);
}
