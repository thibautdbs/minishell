/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:04:18 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/16 08:51:35 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/utils.h"

#include <unistd.h>
#include <dirent.h>
#include <stddef.h>

#include "libft.h"

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

void	my_close_all(void)
{
	int				fd;
	DIR				*dir;
	struct dirent	*file;

	dir = opendir("/proc/self/fd");
	file = readdir(dir);
	while (file != NULL)
	{
		if (ft_isdigit(file->d_name[0]))
		{
			fd = ft_atoi(file->d_name);
			if (2 < fd && fd < OPEN_MAX)
				close(fd);
		}
		file = readdir(dir);
	}
	closedir(dir);
}
