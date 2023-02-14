/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:32:27 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/14 11:50:06 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELST_H
# define PIPELST_H

////////////////////////////////////////////////////////////////////////////////
/// DECLARATIONS

typedef struct s_pipelst	t_pipelst;

////////////////////////////////////////////////////////////////////////////////
/// DEFINITIONS

typedef struct s_pipelst
{
	int			fd[2];
	int			*in;
	int			*out;
	t_pipelst	*next;
}	t_pipelst;

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

t_pipelst	*my_pipelst_new(void);
void		my_pipelst_del(t_pipelst **pipes);
void		my_pipelst_add_back(t_pipelst **pipes, t_pipelst *new);
t_pipelst	*my_pipelst_init(int len);
t_pipelst	*my_pipelst_at(t_pipelst *pipes, int index);

#endif //PIPELST_H
