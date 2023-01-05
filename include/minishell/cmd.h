/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:56:33 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 10:07:03 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "minishell/token.h"

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef struct s_cmd	t_cmd;

typedef enum e_cmd_type
{
	OR,
	AND,
	PIPE,
	EXEC
}	t_cmd_type;

typedef struct s_cmd
{
	t_cmd_type		type;
	t_cmd			*left;
	t_cmd			*right;
	char			*args;
}	t_cmd;

////////////////////////////////////////////////////////////////////////////////
/// FCTS

t_cmd *parse(t_token *toks)
{
}

#endif //CMD_H
