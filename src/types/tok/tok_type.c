/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 07:57:03 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/20 09:25:50 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/tok.h"

#include "libft.h"

t_tok_t	my_tok_type(char const *str)
{
	my_tok_skip_blanks(&str);
	if (*str == '\0')
		return (EOS);
	else if (ft_strncmp(str, "<<", 2) == 0)
		return (LESSLESS);
	else if (ft_strncmp(str, "<", 1) == 0)
		return (LESS);
	else if (ft_strncmp(str, ">>", 2) == 0)
		return (GREATGREAT);
	else if (ft_strncmp(str, ">", 1) == 0)
		return (GREAT);
	else if (ft_strncmp(str, "||", 2) == 0)
		return (BARBAR);
	else if (ft_strncmp(str, "|", 1) == 0)
		return (BAR);
	else if (ft_strncmp(str, "&&", 2) == 0)
		return (AMPAMP);
	else if (ft_strncmp(str, "(", 1) == 0)
		return (LPAR);
	else if (ft_strncmp(str, ")", 1) == 0)
		return (RPAR);
	return (WORD);
}
