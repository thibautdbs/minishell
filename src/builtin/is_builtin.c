/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:29:35 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 17:34:40 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //ft_strncmp

t_bool	my_is_builtin(char	*cmd)
{
	if (ft_strncmp(cmd , "cd", 3) == 0)
		return (TRUE);
	if (ft_strncmp(cmd , "echo", 5) == 0)
		return (TRUE);
	if (ft_strncmp(cmd , "env", 4) == 0)
		return (TRUE);
	if (ft_strncmp(cmd , "pwd", 4) == 0)
		return (TRUE);
	if (ft_strncmp(cmd , "export", 7) == 0)
		return (TRUE);
	if (ft_strncmp(cmd , "unset", 6) == 0)
		return (TRUE);
	if (ft_strncmp(cmd , "exit", 5) == 0)
		return (TRUE);
	return (FALSE);
}
