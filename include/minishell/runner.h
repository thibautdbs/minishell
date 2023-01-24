/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:46:18 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/24 12:00:33 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUNNER_H
# define RUNNER_H

# include "libft.h"
# include "redir.h"

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef t_success	t_opener(t_redir *);

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

t_success	my_open_input(t_redir *redir);
t_success	my_open_output(t_redir *redir);
t_success	my_open_append(t_redir *redir);
t_success	my_open_heredoc(t_redir *redir);

#endif//RUNNER_H
