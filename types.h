/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:26 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/11 15:58:23 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #############################################################################
// ## slst.h                                                                   #
// #############################################################################

#ifndef SLST_H
# define SLST_H

////////////////////////////////////////////////////////////////////////////////
/// TYPE DECLARATIONS

typedef struct	s_slst	t_slst;

////////////////////////////////////////////////////////////////////////////////
/// TYPE DEFINITIONS

typedef struct	s_slst
{
	char	*content;
	t_slst	*next;
}	t_slst;

#endif //SLST_H

// #############################################################################
// ## redir.h                                                                  #
// #############################################################################

#ifndef REDIR_H
# define REDIR_H

////////////////////////////////////////////////////////////////////////////////
/// TYPE DECLARATIONS

typedef struct s_redir	t_redir;
typedef enum e_redir_t	t_redir_t;

////////////////////////////////////////////////////////////////////////////////
/// TYPE DEFINITIONS

typedef enum e_redir_t
{
	INFILE,
	OUTFILE,
	APPNDFILE,
	HEREDOC
}	t_redir_t;

typedef struct s_redir
{
	t_redir_t	type;
	char		*filename;
	t_redir		*next;
}	t_redir;

#endif //REDIR_H

// #############################################################################
// ## cmd.h                                                                    #
// #############################################################################

#ifndef CMD_H
# define CMD_H

////////////////////////////////////////////////////////////////////////////////
/// TYPE DECLARATIONS

/// NODE TYPE

typedef struct s_cmd	t_cmd;
typedef enum e_cmd_t	t_cmd_t;
typedef union u_cmd_v	t_cmd_v;

/// NODE CONTENT

typedef struct s_cmd_lst	t_cmd_lst;
typedef struct s_smpl_cmd	t_smpl_cmd;

////////////////////////////////////////////////////////////////////////////////
/// TYPE DEFINITIONS

/// NODE TYPE

typedef enum e_cmd_t
{
	CMD_SIMPLE,
	CMD_SUBSHELL,
	CMD_PIPELST,
	CMD_ANDLST,
	CMD_ORLST,
}	t_cmd_t;

typedef union u_cmd_v
{
	t_cmd		*as_cmd;
	t_cmd_lst	*as_cmd_lst;
	t_smpl_cmd	*as_smpl_cmd;
}	t_cmd_v;

typedef struct s_cmd
{
	t_cmd_t	type;
	t_cmd_v	val;
}	t_cmd;

/// NODE CONTENT

typedef struct s_cmd_lst
{
	t_cmd		*cmd;
	t_cmd_lst	*next;
}	t_cmd_lst;


typedef struct s_smpl_cmd
{
	t_slst	*words;
	t_redir	*redirs;
}	t_smpl_cmd;


#endif //CMD_H
