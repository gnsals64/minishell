/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:37 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/31 14:14:17 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(void)
{
	char	pwd[MAX_BUF];

	if (!getcwd(pwd, MAX_BUF))
	{
		ft_putstr_fd("pwd error\n", 2);
		g_global.exit_code = 1;
		exit (1);
	}
	else
	{
		printf("%s\n", pwd);
		g_global.exit_code = 0;
		return ;
	}
}
