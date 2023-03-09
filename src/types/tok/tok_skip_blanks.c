/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_skip_blanks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:34:26 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/10 10:35:48 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/tok.h"

#include "libft.h"

void	my_tok_skip_blanks(char const **pstr)
{
	*pstr += ft_strspn(*pstr, " \t\n");
}
