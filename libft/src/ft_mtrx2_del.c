/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx2_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:40:23 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/15 18:41:27 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t
#include <stdlib.h> // FREE

void	ft_mtrx2_del(void *mtrx2, size_t nmemb)
{
	char	**cmtrx2;
	size_t	i;

	cmtrx2 = mtrx2;
	i = 0;
	while (i < nmemb)
	{
		ft_memdel(cmtrx2 + i);
		i++;
	}
	free(cmtrx2);
}
