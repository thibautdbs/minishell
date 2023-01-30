/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:36:23 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/30 17:45:05 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOK_H
# define TOK_H

typedef enum e_tot_t
{
	EOF,
	WORD,
	BLANKS,
	LESS,
	LESSLESS,
	GREAT,
	GREATGREAT,
	BAR,
	BARBAR,
	AMPAMP,
	LPAR,
	RPAR
}	t_tok_t;

#endif //TOK_H
