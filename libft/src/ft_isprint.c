/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:50:36 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/06 12:28:06 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_isprint
#define PRINTABLE_LOWERBOUND ' '
#define PRINTABLE_UPPERBOUND '~'

int	ft_isprint(int c)
{
	return (PRINTABLE_LOWERBOUND <= c && c <= PRINTABLE_UPPERBOUND);
}
