/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:37:23 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/04 12:43:16 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include "minishell/token.h"

//---Print Token functions-----------------------------------------------------
void    dev_print_one_token(t_token const *tok);
void    dev_print_token(t_token const *tok);

#endif
