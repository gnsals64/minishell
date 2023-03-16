/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:49:05 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/17 00:41:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_valid_exit_command(char *str)
{
	
}

void	ft_exit(t_node *node)
{
	int	exit_code;

	if (!node->cmd[1])
		exit (0);
	if (is_valid_exit_command(node->cmd[1]) != 1)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(node->cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	if (node->cmd[1] != 0 && node->cmd[2] != 0)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return ;
	}
	exit_code = ft_atoi(*(node->cmd[1]));
	exit(exit_code);
}