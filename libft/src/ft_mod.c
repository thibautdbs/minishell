/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:29:12 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/26 23:58:59 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mod(int n, int mod)
{
	if (n >= 0)
		return (n % mod);
	while (n < 0)
		n += mod;
	return (n);
}
