/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:25:06 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/24 11:57:45 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "libft.h"

typedef struct s_ctx
{
	t_strlst	*env;
	int			exitcode;
}	t_ctx;

extern t_ctx	*g_ctx;

#endif //CTX_H
