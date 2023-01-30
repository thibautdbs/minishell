/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirlst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:26:59 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/30 17:32:06 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRLST_H
# define REDIRLST_H

////////////////////////////////////////////////////////////////////////////////
/// INCLUDES

# include "wordlst.h"

////////////////////////////////////////////////////////////////////////////////
/// DECLARATIONS

typedef struct s_redirlst	t_redirlst;

////////////////////////////////////////////////////////////////////////////////
/// DEFINITIONS

typedef enum e_redirlst_t
{
	APPND,
	INFILE,
	OUTFILE,
	HEREDOC
}	t_redirlst_t;

typedef struct s_redirlst
{
	t_redirlst_t	type;
	t_wordlst		*word;
	t_redirlst		*next;
}	t_redirlst;

#endif //REDIRLST_H
