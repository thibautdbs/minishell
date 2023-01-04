/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:17:19 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/23 18:27:52 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min_arr(int const *nbrs, size_t size)
{
	int		min;
	size_t	i;

	if (nbrs == NULL || size == 0)
		return (0);
	min = nbrs[0];
	i = 1;
	while (i < size)
	{
		min = ft_min(min, nbrs[i]);
		i++;
	}
	return (min);
}
