/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:10:23 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 12:09:22 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wordlst.h"

#include "libft.h" //ft_strdup
#include <stddef.h> //NULL

t_wordlst	*my_wordlst_new(void)
{
	t_wordlst 	*word;

	word = ft_calloc(1, sizeof(t_wordlst));
	if (word == NULL)
		return (NULL);
	word->next = NULL;
	word->content = NULL;
	return (word);
}
