/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:25:38 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 16:02:48 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c);

int	ft_toupper(int c)
{
	if (ft_islower(c))
	{
		return (c - 'a' + 'A');
	}
	return (c);
}

static int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}
