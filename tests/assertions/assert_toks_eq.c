/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_toks_eq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:17:49 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/13 16:52:26 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

#include "minishell/toks.h"

TEST	ASSERT_TOKS_EQ(t_toks *ref, t_toks *yours)
{
	while (ref != NULL)
	{
		ASSERT_NEQ(NULL, yours);
		ASSERT_EQ(ref->type, yours->type);
		ASSERT_NEQ(NULL, yours->content);
		ASSERT_STR_EQ(ref->content, yours->content);
		ref = ref->next;
		yours = yours->next;
	}
	ASSERT_EQ(NULL, yours);
	PASS();
}
