/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirlst_del_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:52:04 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 15:52:31 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/redirlst.h"

#include <stddef.h>//NULL

#include "libft.h"//memdel
#include "minishell/wordlst.h"

void	my_redirlst_del_one(t_redirlst **predirlst)
{
	if (*predirlst == NULL)
		return ;
	my_wordlst_del(&(*predirlst)->word);
	ft_memdel(predirlst);
}
