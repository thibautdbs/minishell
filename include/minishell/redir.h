/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:40:45 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/06 16:32:06 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

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
	char			*file;
	t_redir_type	type;
	t_redir			*next;
}	t_redir;

///////////////////////////////////////////////////////////////////////////////
/// FCTS

#endif //REDIR_H
