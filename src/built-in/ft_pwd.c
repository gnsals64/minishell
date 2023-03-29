/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:37 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/29 23:23:07 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(void)
{
	char	pwd[MAX_BUF];

	if (!getcwd(pwd, MAX_BUF))
	{
		ft_putstr_fd("pwd error\n", 2);
		exit (1);
		g_global.exit_code = 1;
	}
	else
	{
		printf("%s\n", pwd);
		return ;
		g_global.exit_code = 0;
	}
}
