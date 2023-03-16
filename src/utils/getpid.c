/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:08:55 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/13 23:10:52 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/utils.h"

#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

int	my_getpid(void)
{
	int		fd;
	int		pid;
	char	buf[21];

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd == -1)
		return (-1);
	ft_bzero(buf, sizeof(buf));
	read(fd, buf, sizeof(buf) - 1);
	close(fd);
	pid = ft_atoi(buf);
	if (pid == 0)
		return (-1);
	return (pid);
}
