/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:10:10 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/06 12:09:01 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

#include <stdio.h>
#include <unistd.h>

#include "minishell/cmd.h"
#include "libft.h"

static void	loc_print_rpt(char const *str, int depth)
{
	for (int i = 0; i < depth; i++)
	{
		printf("%s", str);
	}
}

void	dev_print_one_cmd(t_cmd *cmd, int depth)
{
 	char const  *cmd_types[] = {"CMD_OR", "CMD_AND", "CMD_PIPE", "CMD_EXEC"};
	
	loc_print_rpt("   |   ", depth);
	printf(YELLOW"---- CMD ----\n"NC);
	loc_print_rpt("       ", depth);
	printf("Cmd type : %s\n", cmd_types[cmd->type]);
	loc_print_rpt("       ", depth);
	printf("left : %p\n", cmd->left);
	loc_print_rpt("       ", depth);
	printf("right : %p\n",  cmd->right);
	loc_print_rpt("       ", depth);
	printf("args : ");
	if (cmd->type == CMD_EXEC)
	{
		for(int i =0; cmd->args[i] != NULL; i++)
			printf(BLUE"\"%s\" "NC,  cmd->args[i]);
	}
	printf("\n\n");
}

void	dev_print_cmd(t_cmd *cmd, int depth)
{
	if (cmd == NULL)
		return ;
	dev_print_one_cmd(cmd, depth);
	if (cmd->type != CMD_EXEC)
	{
		dev_print_cmd(cmd->left, depth + 1);
		dev_print_cmd(cmd->right, depth + 1);
	}
}

// int	main(void)
// {
// 	//Tree creation
// 	t_cmd	cmd0;
// 	t_cmd	cmd10;
// 	t_cmd	cmd11;
//
// 	cmd0.type = CMD_OR;
// 	cmd0.left = &cmd10;
// 	cmd0.right = &cmd11;
// 	cmd0.args = (char*[]){"yo", "YO", NULL};
//
// 		cmd10.type = CMD_EXEC;
// 		cmd10.left = NULL;
// 		cmd10.right = NULL;
// 		cmd10.args = (char*[]){"yo", "YO", NULL};
//
// 		cmd11.type = CMD_AND;
// 		cmd11.left = NULL;
// 		cmd11.right = NULL;
// 		cmd11.args = NULL;
// 		cmd11.args = (char*[]){"yo", "YO", NULL};
//
// 	dev_print_cmd(&cmd0, 0);
// }
