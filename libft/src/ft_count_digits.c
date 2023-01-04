/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:50:02 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 16:01:06 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits(int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		count += 1;
		n = n / 10;
	}
	return (count);
}
