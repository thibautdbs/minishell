/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:10:10 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/06 11:25:40 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "minishell/cmd.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	dev_print_one_cmd(t_cmd *cmd, int depth)
{
	int	i;
 	char const  *cmd_types[] = {"CMD_OR", "CMD_AND", "CMD_PIPE", "CMD_EXEC"};
	
	ft_putstr_rpt_fd("   |   ", depth, 1);
	printf(YELLOW"---- CMD ----\n"NC);
	ft_putstr_rpt_fd("       ", depth, 1);
	printf("Cmd type : %s\n", cmd_types[cmd->type]);
	ft_putstr_rpt_fd("       ", depth, 1);
	printf("left : %p\n", cmd->left);
	ft_putstr_rpt_fd("       ", depth, 1);
	printf("right : %p\n",  cmd->right);
	ft_putstr_rpt_fd("       ", depth, 1);
	printf("args : ");
	i = 0;
	while (cmd->args[i])
	{
		printf(BLUE"\"%s\" "NC,  cmd->args[i]);
		i++;
	}
	printf("\n\n");
}

void	dev_print_cmd(t_cmd *cmd, int depth)
{
	if (cmd == NULL)
		return ;
	dev_print_one_cmd(cmd, depth);
	if (cmd->left != NULL)
		dev_print_cmd(cmd->left, depth + 1);
	if (cmd->right != NULL)
		dev_print_cmd(cmd->right, depth + 1);
}

int	main(void)
{
	//Tree creation
	t_cmd	cmd0;
	t_cmd	cmd10;
	t_cmd	cmd11;

	cmd0.type = CMD_OR;
	cmd0.left = &cmd10;
	cmd0.right = &cmd11;
	cmd0.args = (char*[]){"yo", "YO", NULL};

		cmd10.type = CMD_EXEC;
		cmd10.left = NULL;
		cmd10.right = NULL;
		cmd10.args = (char*[]){"yo", "YO", NULL};

		cmd11.type = CMD_AND;
		cmd11.left = NULL;
		cmd11.right = NULL;
		cmd11.args = NULL;
		cmd11.args = (char*[]){"yo", "YO", NULL};

	dev_print_cmd(&cmd0, 0);
}
