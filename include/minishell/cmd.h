/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:56:33 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/06 17:35:42 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "token.h"
# include "redir.h"

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef struct s_cmd	t_cmd;
typedef struct s_chunk	t_chunk;

typedef enum e_cmd_type
{
	CMD_OR,
	CMD_AND,
	CMD_PIPE,
	CMD_EXEC
}	t_cmd_type;

typedef struct s_cmd
{
	t_cmd_type		type;
	t_cmd			*left;
	t_cmd			*right;
	char			**args;
	t_redir			*redirs;
}	t_cmd;

////////////////////////////////////////////////////////////////////////////////
/// FCTS

t_cmd	*my_parse(t_token *toks);

void	my_cmd_destroy(t_cmd **cmd);

#endif //CMD_H
