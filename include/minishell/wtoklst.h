/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:01:59 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/02 15:32:00 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WTOKLST_H
# define WTOKLST_H

////////////////////////////////////////////////////////////////////////////////
/// TYPES DECLARATIONS

typedef enum e_wtoklst_t	t_wtoklst_t;
typedef struct s_wtoklst	t_wtoklst;

typedef t_wtoklst	*t_wtokenizer(char const **pstr);

////////////////////////////////////////////////////////////////////////////////
/// TYPES DEFINITIONS

typedef enum e_wtoklst_t
{
	QTD_VAR,
	BLANKS,
	CHARS,
	VAR
}	t_wtoklst_t;

typedef struct s_wtoklst
{
	t_wtoklst_t	type;
	char		*content;
	t_wtoklst	*next;
}	t_wtoklst;

#endif //WTOKLST_H
