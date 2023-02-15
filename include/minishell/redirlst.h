/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirlst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:26:59 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/15 15:50:19 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRLST_H
# define REDIRLST_H

////////////////////////////////////////////////////////////////////////////////
/// INCLUDES

# include "wordlst.h"

////////////////////////////////////////////////////////////////////////////////
/// DECLARATIONS

typedef struct s_redirlst	t_redirlst;

////////////////////////////////////////////////////////////////////////////////
/// DEFINITIONS

typedef enum e_redirlst_t
{
	APPND,
	INFILE,
	OUTFILE,
	HEREDOC
}	t_redirlst_t;

typedef struct s_redirlst
{
	t_redirlst_t	type;
	t_wordlst		*word;
	t_redirlst		*next;
}	t_redirlst;

t_redirlst	*my_redirlst_new(t_redirlst_t type);
void		my_redirlst_del(t_redirlst **predirlst);
void		my_redirlst_del_one(t_redirlst **predirlst);
t_redirlst	*my_redirlst_last(t_redirlst *redirs);
t_redirlst	*my_redirlst_pop_front(t_redirlst **predirlst);
void		my_redirlst_add_back(t_redirlst **predirs, t_redirlst *new);
void		my_redirlst_add_front(t_redirlst **predirs, t_redirlst *new);

#endif //REDIRLST_H
