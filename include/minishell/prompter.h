/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 02:40:45 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/10 02:35:37 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPTER_H
# define PROMPTER_H

# include "envlst.h"
# include "redirlst.h"
# include "cmd.h"

int	my_prompt(t_envlst **penvlst);

int	my_prompt_heredocs(t_cmdtree *cmdtree);
int	my_prompt_heredoc(t_redirlst *redir);

#endif //PROMPTER_H
