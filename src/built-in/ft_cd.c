/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:10 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/19 13:25:55 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env	*find_env(char *key)
{
	t_env	*cur;

	cur = g_global.env_lst;
	while (!cur)
	{
		if (ft_strcmp(cur->value, key) == 0)
			
	}
}

void	change_pwd_env(char *pwd)
{
	t_env	*pwd_env;

	pwd_env = find_env("PWD");
	if (pwd)
		pwd_env->value = ft_strdup(pwd);
	else
		pwd_env->value = ft_strdup("");
	if (!pwd_env->value)
		ft_putstr_fd("memory error",2);
}

void	ft_cd(t_node *node)
{
	char	*path;
	char	pwd[MAX_BUF];

	if (!node->cmd || node->cmd[1] == NULL)
	{
		ft_putstr_fd("argument error\n", 2);
		g_global.exit_code = 1;
		return ;
	}
	path = node->cmd[1];
	if (chdir(path) == -1 || !getcwd(pwd, MAX_BUF))
	{
		ft_putstr_fd("fail directory change\n", 2);
		g_global.exit_code = 1;
		return ;
	}
	change_pwd_env(pwd);
	g_global.exit_code = 0;
}