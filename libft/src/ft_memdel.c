/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:09:42 by tdubois           #+#    #+#             */
/*   Updated: 2022/12/15 11:46:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h> // free
#include <stddef.h> // NULL

void	ft_memdel(void *ptrptr)
{
	char	**cptrptr;

	cptrptr = ptrptr;
	if (*cptrptr == NULL)
		return ;
	free(*cptrptr);
	*cptrptr = NULL;
}
