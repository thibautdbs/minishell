/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:29:11 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/24 16:51:13 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "redirs.h"
# include "toks.h"

////////////////////////////////////////////////////////////////////////////////
/// TYPES DECLARATIONS

typedef enum e_cmd_t	t_cmd_t;
typedef union u_cmd_v	t_cmd_v;
typedef struct s_cmd	t_cmd;

typedef struct s_smpl_cmd	t_smpl_cmd;
typedef struct s_subshell	t_subshell;
typedef struct s_cmd_lst	t_cmd_lst;

////////////////////////////////////////////////////////////////////////////////
/// TYPES DEFINITIONS

/// T_CMD

typedef enum e_cmd_t
{
	CMD_SMPL_CMD,
	CMD_SUBSHELL,
	CMD_PIPELST,
	CMD_ANDLST,
	CMD_ORLST
}	t_cmd_t;

typedef union u_cmd_v
{
	t_smpl_cmd	*as_smpl_cmd;
	t_subshell	*as_subshell;
	t_cmd_lst	*as_cmd_lst;
}	t_cmd_v;

typedef struct s_cmd
{
	t_cmd_t	type;
	t_cmd_v	val;
}	t_cmd;

/// T_CMD CONTENT

typedef struct s_smpl_cmd
{
	t_toks		*words;
	t_redirs	*redirs;
}	t_smpl_cmd;

typedef struct s_subshell
{
	t_cmd		*cmd;
	t_redirs	*redirs;
}	t_subshell;

typedef struct s_cmd_lst
{
	t_cmd		*cmd;
	t_cmd_lst	*next;
}	t_cmd_lst;

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

///CMD
t_cmd		*my_cmd_create(t_cmd_t type);
void		my_cmd_destroy(t_cmd **pcmd);

///SUBSHELL
t_subshell	*my_subshell_create(void);
void		my_subshell_destroy(t_subshell **psubshell);

///CMD_LST
t_cmd_lst	*my_cmd_lst_create(t_cmd *cmd);
void		my_cmd_lst_add_back(t_cmd_lst **cmd_lst, t_cmd_lst *new_cmd);
t_cmd_lst	*my_cmd_lst_last(t_cmd_lst *cmd_lst);

#endif //CMD_H
