/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_handle_ast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:48:57 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 16:52:05 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include "libft.h"

t_wtoklst	*my_wtoklst_handle_ast(char const **pstr)
{
	*pstr += ft_strspn(*pstr, "*");
	return (my_wtoklst_new(WILDCARD, "*", 1));
}
