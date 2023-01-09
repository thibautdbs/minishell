/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:40:45 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/09 15:15:17 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include "minishell/arg.h"

typedef struct s_redir	t_redir;

typedef enum	e_redir_type
{
	INPUT,
	HEREDOC,
	OUTPUT,
	APPEND,
}	t_redir_type;

typedef struct s_redir
{
	t_arg			*arg;
//	char			*file; sert a rien si on a arg
	t_redir_type	type;
	t_redir			*next;
}	t_redir;

///////////////////////////////////////////////////////////////////////////////
/// FCTS

void	my_redir_destroy(t_token **redir);

#endif //REDIR_H
