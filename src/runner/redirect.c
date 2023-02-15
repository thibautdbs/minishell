/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:47:54 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/14 20:59:12 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include "minishell/redirlst.h"
#include "minishell/envlst.h"

int	my_redirect(t_redirlst *redir, t_envlst *envlst, int res)
{
	while (redir != NULL)
	{
		 


	}
	return (errno);
}

int	loc_redir_one(t_redirlst *redir, t_envlst *envlst, int res)
{
	if (redir->type == HEREDOC)	
	{
		
	}	

}
