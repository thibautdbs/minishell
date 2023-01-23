/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_smpl_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:22:45 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/23 16:28:45 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/toks.h"

t_cmd_or_err	my_parse_smpl_cmd(t_toks const **ptoks)
{
	t_cmd_or_err	res;

	my_parse_skip_blanks(ptoks);
	if (my_toks_is_control_operator(*ptoks))
		return ((t_cmd_or_err){.err = NO_ERR, .cmd = NULL});
	while (*ptoks != NULL && !my_toks_is_control_operator(*ptoks))
	{
		if (my_toks_is_redir(*ptoks))
			loc_extract_redir();
		else
			loc_extract_word();
		//check error
		my_parse_skip_blanks(ptoks);
	}
	return (res);
}
