/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:07:26 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/09 01:23:25 by tdubois          ###   ########.fr       */
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
/// CMDLST

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

t_cmdlst	*my_cmdlst_new(t_cmdlst_t type);
void		my_cmdlst_del(t_cmdlst **pcmdlst);
void		my_cmdlst_del_one(t_cmdlst **pcmdlst);

t_cmdlst	*my_cmdlst_last(t_cmdlst *cmdlst);
t_cmdlst	*my_cmdlst_pop_front(t_cmdlst **pcmdlst);
void		my_cmdlst_add_back(t_cmdlst **pcmdlst, t_cmdlst *new);
int			my_cmdlst_size(t_cmdlst *lst);

////////////////////////////////////////////////////////////////////////////////
/// CMDTREE

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

t_cmdtree	*my_cmdtree_new(t_cmdtree_t type);
void		my_cmdtree_del(t_cmdtree **pcmdtree);

#endif //CMD_H
