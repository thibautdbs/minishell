/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:07:26 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/30 17:52:38 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

////////////////////////////////////////////////////////////////////////////////
/// INCLUDES

# include "redirlst.h"
# include "wordlst.h"

////////////////////////////////////////////////////////////////////////////////
/// DECLARATIONS

typedef struct s_cmdlst		t_cmdlst;
typedef struct s_cmdtree	t_cmdtree;

////////////////////////////////////////////////////////////////////////////////
/// DEFINITIONS

typedef enum e_cmdlst
{
	SIMPLECMD,
	SUBSHELL
}	t_cmdlst_t;

typedef struct s_cmdlst
{
	t_cmdlst_t	type;
	t_redirlst	*redirs;
	t_cmdtree	*subcmd;
	t_wordlst	*words;
	t_cmdlst	*next;
}	t_cmdlst;

typedef enum e_cmdtree_t
{
	PIPELINE,
	AND,
	OR
}	t_cmdtree_t;

typedef struct s_cmdtree
{
	t_cmdtree_t	type;
	t_cmdlst	*pipeline;
	t_cmdtree	*left;
	t_cmdtree	*right;
}	t_cmdtree;

#endif //CMD_H
