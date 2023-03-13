/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:33:10 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/13 17:41:04 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

////////////////////////////////////////////////////////////////////////////////
/// WAIT

int		my_waitpid(int pid);
void	my_waitall(void);

////////////////////////////////////////////////////////////////////////////////
/// SIGNAL

int		my_signal(int signum, void (handler)(int signum));

#endif //UTILS_H
