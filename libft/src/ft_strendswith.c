/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:04:09 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/09 16:18:35 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t

t_bool	ft_strendswith(char const *str, char const *end)
{
	size_t const	str_len = ft_strlen(str);
	size_t const	end_len = ft_strlen(end);

	if (str_len < end_len)
		return (FALSE);
	if (ft_strcmp(str + str_len - end_len, end) != 0)
		return (FALSE);
	return (TRUE);
}
