/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks_del_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 13:15:59 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/toks.h"

#include "libft.h"
#include <stddef.h>//NULL

void	my_toks_del_one(t_toks **toks)
{
	t_tok_t const	redir_types[4] = {INFILE, OUTFILE, APPNDFILE, HEREDOC};

	if (*toks == NULL)
		return ;
	if (my_toks_type_match(*toks, redir_types, 4))
		my_toks_del(&(*toks)->val.as_toks);
	else
		ft_memdel(&(*toks)->val.as_str);
	ft_memdel(toks);
}
