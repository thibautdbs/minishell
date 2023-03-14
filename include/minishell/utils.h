/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:33:10 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/14 11:58:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

typedef struct s_globals
{
	bool	did_receive_sigint;
	bool	did_exit;
}	t_globals;

////////////////////////////////////////////////////////////////////////////////
/// WAIT

int		my_waitpid(int pid);
void	my_waitall(void);

////////////////////////////////////////////////////////////////////////////////
/// SIGNAL

int		my_signal(int signum, void (handler)(int signum));

////////////////////////////////////////////////////////////////////////////////
/// GETPID

int		my_getpid(void);

////////////////////////////////////////////////////////////////////////////////
/// RAISE

int		my_raise(int signum);

////////////////////////////////////////////////////////////////////////////////
/// EXIT_OR_RAISE

void	my_exit_or_raise(int res);

////////////////////////////////////////////////////////////////////////////////
/// CLOSE_ALL

void	my_close_all(void);

#endif //UTILS_H
