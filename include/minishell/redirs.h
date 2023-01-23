/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:45:52 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/23 18:50:16 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRS_H
# define REDIRS_H

# include "toks.h"

typedef struct s_redirs		t_redirs;

typedef enum e_redir_t
{
	INFILE,
	OUTFILE,
	APPNDFILE,
	HEREDOC
}	t_redir_t;

typedef struct s_redirs
{
	t_redir_t	type;
	t_toks		*toks;
	t_redirs	*next;
}	t_redirs;

t_redirs	*my_redirs_create(void);//TODO
void		my_redirs_destroy(t_redirs **predirs);//TODO

void		my_redirs_add_back(t_redirs **predirs, t_redirs *new);//TODO

#endif //REDIRS_H
