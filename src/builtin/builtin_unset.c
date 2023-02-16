/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/16 17:26:27 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL

#include "libft.h" //ft_strchr, ft_puterr, ft_putstr_fd
#include "minishell/envlst.h"

static void	loc_pop_var(char *var, t_envlst *penvlst);
static int	loc_varcmp(char	*str, char *var);

int	my_builtin_unset(t_wordlst *words, t_envlst **penvlst)
{
	int	res;

	res = 0;
	while (words != NULL)
	{
		if (my_is_valid_identifier(words->content, '\0') == FAILURE)
		{
			ft_puterr("minishell: unset: not a valid identifier");
			res = 1;
		}
		loc_pop_var(args[i], penvlst);
		words = words->next;
	}
	return (res);
}

static int	loc_varcmp(char	*str, char *var)
{
	size_t const	len = ft_strlen(var);

	if (ft_strncmp(str, var, len) == 0 && (str[len] == '\0' || str[len] == '='))
		return (0);
	return (1);
}

static void	loc_pop_var(char *var, t_envlst *penvlst)
{
	t_envlst	*curr;
	t_envlst	*tmp;

	curr = penvlst;
	if (curr != NULL && curr->next == NULL
		&& loc_varcmp(curr->next->content, var) == 0)
	{
		ft_memdel(&curr->content);
		ft_memdel(&curr->next);
		curr->next = NULL;
	}
	while (curr != NULL && curr->next != NULL)
	{
		if (loc_varcmp(curr->next->content, var) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			ft_memdel(&tmp->content);
			ft_memdel(&tmp);
		}
		curr = curr->next;
	}
}
