/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_handle_dollar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:45:19 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 16:01:19 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include "libft.h"

static int	loc_get_name_len(char const *str);

t_wtoklst	*my_wtoklst_handle_dollar(char const **pstr)
{
	t_wtoklst	*tok;
	int			len;

	*pstr += 1;
	if (**pstr == '?')
	{
		len = 1;
		tok = my_wtoklst_new(VAR, "?", 1);
	}
	else if (!ft_isalpha(**pstr) && **pstr != '_')
	{
		len = 0;
		tok = my_wtoklst_new(CHARS, "$", 1);
	}
	else
	{
		len = loc_get_name_len(*pstr);
		tok = my_wtoklst_new(VAR, *pstr, len);
	}
	*pstr += len;
	return (tok);
}

static int	loc_get_name_len(char const *str)
{
	int		len;

	len = 0;
	while (ft_isdigit(*str) || ft_isalpha(*str) || *str == '_')
	{
		str++;
		len++;
	}
	return (len);
}
