/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:58:10 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 12:06:59 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

///////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef enum e_redir_t
{
	INPUT,
	HEREDOC,
	OUTPUT,
	APPEND
}	t_redir_t;

typedef struct s_redir
{
	t_redir_t		type;
	char			*label;
	struct s_redir	*next;
}	t_redir;

///////////////////////////////////////////////////////////////////////////////
/// FCTS

void	my_redir_destroy(t_redir **redir);

#endif //REDIR_H