/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:23:41 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 23:37:23 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL, size_t

char	*ft_strtok(char	*str, char const *sep)
{
	static char	*tok = NULL;

	return (ft_strtok_r(str, sep, &tok));
}
