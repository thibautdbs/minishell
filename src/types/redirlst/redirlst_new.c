/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirlst_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:51:38 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 16:54:41 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redirlst.h"

#include <stddef.h>//NULL

#include "libft.h"

t_redirlst	*my_redirlst_new(t_redirlst_t type)
{
	t_redirlst	*redir;

	redir = ft_calloc(1, sizeof(t_redirlst));
	if (redir == NULL)
		return (NULL);
	redir->type = type;
	redir->word = NULL;
	redir->next = NULL;
	return (redir);
}
