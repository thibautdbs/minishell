/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_blanks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:15:26 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 12:26:59 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include "libft.h" //ft_strspn

void	my_skip_blanks(char const **pstr)
{
	*pstr += ft_strspn(*pstr, " /t/n");
}
