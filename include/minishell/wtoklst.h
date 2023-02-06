/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:01:59 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 11:54:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WTOKLST_H
# define WTOKLST_H

////////////////////////////////////////////////////////////////////////////////
/// TYPES DECLARATIONS

typedef enum e_wtoklst_t	t_wtoklst_t;
typedef struct s_wtoklst	t_wtoklst;

typedef t_wtoklst			*t_wtokenizer(char const **pstr);

////////////////////////////////////////////////////////////////////////////////
/// TYPES DEFINITIONS

typedef enum e_wtoklst_t
{
	WILDCARD,
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

t_wtoklst	*my_wtoklst_new(t_wtoklst_t type, char *content);
void		my_wtoklst_del(t_wtoklst **ptoks);
void		my_wtoklst_del_one(t_wtoklst **ptok);
t_wtoklst	*my_wtoklst_last(t_wtoklst *toks);
void		my_wtoklst_add_back(t_wtoklst **ptoks, t_wtoklst *new);
void		my_wtoklst_add_front(t_wtoklst **ptoks, t_wtoklst *new);
t_wtoklst	*my_wtoklst_pop_front(t_wtoklst **ptoks);

t_wtoklst	*my_wtoklst_extract(char const *str);
t_wtoklst	*my_do_word_split(char const *word, char const *sep);
void		my_wtoklst_concat(t_wtoklst **ptoks);
void		my_wtoklst_convert(t_wtoklst *toks, t_wtoklst_t from,
				t_wtoklst_t to);

#endif //WTOKLST_H
