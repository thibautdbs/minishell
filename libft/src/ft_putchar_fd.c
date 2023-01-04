/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:22:02 by tdubois           #+#    #+#             */
/*   Updated: 2022/10/06 12:23:47 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_putchar_fd
#include <unistd.h> // write

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
