/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:53:10 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/06 12:33:17 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_tolower

static int	ft_isupper(int c);

static int	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		return (c - 'A' + 'a');
	}
	return (c);
}
