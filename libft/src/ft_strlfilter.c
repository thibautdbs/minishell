/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlfilter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:54:32 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/07 15:14:41 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strlfilter, ft_strchr
#include <stddef.h> // NULL

void	ft_strlfilter(char const *src, char *dst, char const *filter, int n)
{
	int	i;
	int	j;

	if (n < 1)
		return ;
	i = 0;
	j = 0;
	while (src[i] != '\0' && j < n - 1)
	{
		if (ft_strchr(filter, src[i]) == NULL)
		{
			dst[j] = src[i];
			j += 1;
		}
		i += 1;
	}
	dst[j] = '\0';
}
