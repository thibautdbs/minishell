/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:58:26 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/22 13:49:35 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stdlib.h> //exit

#include "libft.h" //ft_isdigit, ft_islong, ft_atol
#include "minishell/wordlst.h"

int	my_builtin_exit(t_wordlst *words, int res)
{
	char	*endptr;
	char	*nptr;

	if (my_wordlst_size(words) == 1)
		exit(res);
	nptr = my_wordlst_at(words, 1)->content;
	res = (unsigned char) ft_strtol(nptr, &endptr, &res);
	endptr += ft_strspn(endptr, " ");
	if (res == 0 || endptr[0] != '\0')
	{
		ft_puterr("minishell: exit: numeric argument required");
		exit(2);
	}
	if (my_wordlst_size(words) > 2)
	{
		ft_puterr("minishell: exit : too many arguments");
		return (1);
	}
	exit(res);
}
