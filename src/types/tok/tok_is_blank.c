/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_is_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:13:09 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/10 11:15:01 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/tok.h"

#include <stdbool.h>
#include <stddef.h>//NULL

#include "libft.h"//ft_strchr

bool	my_tok_is_blank(char const *str)
{
	return (ft_strchr(" \t\n", str[0]) != NULL);
}
