/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_handle_ast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:48:57 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/21 17:32:51 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include "libft.h"

t_wtoklst	*my_wtoklst_handle_ast(char const **pstr)
{
	int			len;
	t_wtoklst	*tok;

	len = ft_strspn(*pstr, "*");
	tok = my_wtoklst_new(WILDCARD, *pstr, len);
	*pstr += len;
	return (tok);
}
