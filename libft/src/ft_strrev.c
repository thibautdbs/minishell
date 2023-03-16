/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:10:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/10 00:11:52 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>//size_t

/** ft_strrev:
 *   reverses str in place.
 */
void	ft_strrev(char *str)
{
	size_t const	len = ft_strlen(str);
	char			tmp;
	size_t			i;

	i = 0;
	while (i * 2 < len)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
}
