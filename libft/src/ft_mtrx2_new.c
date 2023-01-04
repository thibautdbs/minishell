/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx2_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:39:37 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/15 18:42:11 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t, NULL

void	*ft_mtrx2_new(size_t nmemb_out, size_t nmemb_in, size_t size)
{
	char	**mtrx;
	size_t	i;

	mtrx = ft_calloc(nmemb_out, sizeof(char *));
	if (mtrx == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb_in)
	{
		mtrx[i] = ft_calloc(nmemb_in, size);
		if (mtrx[i] == NULL)
		{
			ft_mtrx2_del(mtrx, i);
			return (NULL);
		}
		i++;
	}
	return (mtrx);
}
