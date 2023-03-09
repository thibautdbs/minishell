/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:32 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/09 15:32:40 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "cmd.h"

int	my_read_heredocs(t_cmdtree *cmdtree);
int	my_read_heredoc(t_redirlst *redir);

#endif //HEREDOC_H
