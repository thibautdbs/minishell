/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:37:23 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 11:29:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "minishell/token.h"
# include "minishell/cmd.h"

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE "\033[0;35m"
# define NC		"\033[0m"

//---Print Token functions------------------------------------------------------
void    dev_print_one_token(t_tok const *tok);
void    dev_print_token(t_tok const *tok);

//---Print Cmd functions--------------------------------------------------------
void	dev_print_one_cmd(t_cmd *cmd, int depth);
void	dev_print_cmd(t_cmd *cmd, int depth);

#endif
