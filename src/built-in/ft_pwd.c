/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:37 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/07 20:29:32 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(void)
{
	char	pwd[MAX_BUF];

	if (!getcwd(pwd, MAX_BUF))
	{
		ft_putstr_fd("pwd error\n", 2);
		return ;
	}
	else
	{
		printf("%s\n", pwd);
		return ;
	}
}