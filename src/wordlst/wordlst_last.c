/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlst_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:30:11 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 17:31:11 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wordlst.h"

#include <stddef.h>//NULL

t_wordlst	*my_wordlst_last(t_wordlst *words)
{
	while (words->next != NULL)
		words = words->next;
	return (words);
}
