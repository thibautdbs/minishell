/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_handle_sgl_quotes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:53:07 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/21 13:39:38 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include "libft.h"//ft_strcspn

t_wtoklst	*my_wtoklst_handle_sgl_quotes(char const **pstr)
{
	t_wtoklst	*tok;
	int			len;

	*pstr += 1;
	len = ft_strcspn(*pstr, "\'");
	tok = my_wtoklst_new(CHARS, *pstr, len);
	*pstr += len + 1;
	return (tok);
}
