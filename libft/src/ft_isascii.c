/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:28:19 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/06 12:28:21 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_isascii
#define ASCII_LOWERBOUND 0
#define ASCII_UPPERBOUND 127

int	ft_isascii(int c)
{
	return (ASCII_LOWERBOUND <= c && c <= ASCII_UPPERBOUND);
}
