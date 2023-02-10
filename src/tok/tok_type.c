/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 07:57:03 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/10 10:41:51 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/tok.h"

#include "libft.h"

t_tok_t	my_tok_type(char const *str)
{
	my_tok_skip_blanks(&str);
	if (*str == '\0')
		return (EOS);
	else if (ft_strncmp(str, "<<", 2))
		return (LESSLESS);
	else if (ft_strncmp(str, "<", 1))
		return (LESS);
	else if (ft_strncmp(str, ">>", 2))
		return (GREATGREAT);
	else if (ft_strncmp(str, ">", 1))
		return (GREAT);
	else if (ft_strncmp(str, "||", 2))
		return (BARBAR);
	else if (ft_strncmp(str, "|", 1))
		return (BAR);
	else if (ft_strncmp(str, "&&", 2))
		return (AMPAMP);
	else if (ft_strncmp(str, "(", 1))
		return (LPAR);
	else if (ft_strncmp(str, ")", 1))
		return (RPAR);
	return (WORD);
}
