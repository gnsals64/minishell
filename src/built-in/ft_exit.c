/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:49:05 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/20 16:10:48 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_valid_exit_command(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

void	ft_exit(t_argv *node)
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
		g_global.exit_code = 1;
		return ;
	}
	exit_code = ft_atoi(*(node->cmd[1]));
	exit(exit_code);
}