/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:25:18 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 21:40:01 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h> // write
#include <stddef.h> // NULL

void	ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
	{
		return ;
	}
	write(fd, s, ft_strlen(s));
}
