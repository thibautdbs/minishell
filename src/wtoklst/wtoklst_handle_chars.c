/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_handle_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:12:50 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 17:15:46 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include "libft.h"

t_wtoklst	*my_wtoklst_handle_chars(char const **pstr)
{
	t_wtoklst	*tok;
	int			len;

	len = ft_strcspn(*pstr, "$\"\'*");
	tok = my_wtoklst_new(CHARS, *pstr, len);
	*pstr += len;
	return (tok);
}
