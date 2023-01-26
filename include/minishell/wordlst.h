/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:23:28 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/26 18:25:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLST_H
# define WORDLST_H

////////////////////////////////////////////////////////////////////////////////
/// DECLARATIONS

typedef struct s_wordlst	t_wordlst;

////////////////////////////////////////////////////////////////////////////////
/// DEFINITIONS

typedef struct s_wordlst
{
	char		*content;
	t_wordlst	*next;
}	t_wordlst;

#endif //WORDLST_H

