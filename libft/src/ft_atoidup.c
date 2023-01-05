/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoidup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:10:38 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/22 10:31:10 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_atoidup(void *nptr)
{
	int const	n = ft_atoi((char *)nptr);

	return (ft_memdup(&n, sizeof(int)));
}
