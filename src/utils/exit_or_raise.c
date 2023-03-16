/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_or_raise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:28:13 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/13 23:39:07 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/utils.h"

#include <stdlib.h>
#include <signal.h>

void	my_exit_or_raise(int res)
{
	if (res >= 0)
		exit(res);
	if (res < 128)
	{
		my_signal(-(res + 128), SIG_DFL);
		my_raise(-(res + 128));
	}
	exit(1);
}
