/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:36:00 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 16:01:48 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_has_twodigits(int n);

void	ft_putnbr_fd(int n, int fd)
{
	int	first_digits;
	int	last_digit;

	first_digits = n / 10;
	last_digit = n % 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		first_digits = -first_digits;
		last_digit = -last_digit;
	}
	if (ft_has_twodigits(n))
	{
		ft_putnbr_fd(first_digits, fd);
	}
	ft_putchar_fd(ft_tochar(last_digit), fd);
}

static int	ft_has_twodigits(int n)
{
	return (n / 10 != 0);
}
