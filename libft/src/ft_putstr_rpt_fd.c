/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_rpt_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:32:02 by tdubois           #+#    #+#             */
/*   Updated: 2022/11/07 14:45:16 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_putstr_rpt_fd, ft_strlen
#include <unistd.h> // write

void	ft_putstr_rpt_fd(char const *str, int n, int fd)
{
	int	i;
	int	len;

	if (str == NULL)
		return ;
	len = ft_strlen(str);
	i = 0;
	while (i < n)
	{
		write(fd, str, len);
		i += 1;
	}
}
