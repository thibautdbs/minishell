/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:31:20 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/16 21:53:40 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

void	ft_putendl_fd(char const *s, int fd)
{
	if (s == NULL)
	{
		return ;
	}
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
