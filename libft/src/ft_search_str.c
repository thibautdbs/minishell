/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:16:15 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/17 13:32:56 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_search_str(char const *str, char **strs, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(str, strs[i]) == 0)
			return (strs[i]);
	}
	return (NULL);
}
