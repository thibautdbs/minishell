/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:32:27 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 12:32:31 by ffeaugas         ###   ########.fr       */
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

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

void		my_wordlst_del(t_wordlst **word);
t_wordlst	*my_wordlst_new(void);

#endif //WORDLST_H
