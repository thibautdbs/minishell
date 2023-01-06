/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:58:30 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/06 17:27:00 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_success	my_parse_arg(t_redir **redirs, t_arg *args, t_token *toks)
{
	if (toks == NULL)
		return (failure);
	if (toks->type == WORD && toks->next != NULL && toks-type != WORD)
	{
		my_arg_addback(args, token->content);
	}
}
