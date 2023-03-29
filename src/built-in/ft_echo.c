/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:50:59 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/30 01:16:46 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_n_option(char *arg)
{
	if (!arg)
		return (0);
	if (*arg == '-')
		arg++;
	else
		return (0);
	while (*arg == 'n')
		arg++;
	if (*arg == 0)
		return (1);
	return (0);
}

void	ft_echo(t_argv *node)
{
	int		n_option;
	char	**arg;

	arg = &node->cmd[1];
	n_option = 0;
	if (arg)
	{
		n_option = check_n_option(*arg);
		while (*arg)
		{
			if (check_n_option(*arg) && n_option == 1)
				arg++;
			else
			{
				if (n_option == 1)
					n_option++;
				ft_putstr_fd(*arg, 1);
				if (*++arg)
					write(1, " ", 1);
			}
		}
	}
	if (!n_option)
		write(1, "\n", 1);
	g_global.exit_code = 0;
}
