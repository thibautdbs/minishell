/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:59:18 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:59:22 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"
# include "token.h"
# include "redir.h"

////////////////////////////////////////////////////////////////////////////////
/// COMMAND TREE

typedef enum e_cmd_t
{
	PIPELINE,
	ANDLIST,
	ORLIST,
	SUBSHELL,
	EXEC
}	t_cmd_t;

typedef struct s_cmd
{
	t_cmd_t	type;
	void	*content;
}	t_cmd;

////////////////////////////////////////////////////////////////////////////////
/// NODE TYPE

// PIPELINE	-> t_cmdlst *
// ANDLIST	-> t_cmdlst	*
// ORLIST	-> t_cmdlst *

typedef struct s_cmdlst
{
	t_cmd			*content;
	struct s_cmdlst	*next;
}	t_cmdlst;

// SUBSHELL	-> t_subshell *

typedef struct s_subshell
{
	t_redir	*redirs;
	t_cmd	*cmd;
}	t_subshell;

// EXEC		-> t_exec *

typedef struct s_exec
{
	t_redir		*redirs;
	t_strlst	*args;
}	t_exec;

////////////////////////////////////////////////////////////////////////////////
/// FCTS

t_cmd	*my_parse(t_tok *toks);

#endif //CMD_H
