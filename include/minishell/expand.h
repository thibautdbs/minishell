/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:04:40 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 17:40:04 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "wordlst.h"
# include "wtoklst.h"
# include "envlst.h"

t_wordlst	*my_expand(char const *str, t_envlst *env);
void		my_expand_vars(t_wtoklst **ptoks, t_envlst *env);
void		my_expand_qtd_vars(t_wtoklst *toks, t_envlst *env);
void		my_expand_wildcards(t_wtoklst **ptoks);

#endif //EXPAND_H
