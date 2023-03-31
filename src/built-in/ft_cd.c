/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:10 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/31 13:57:33 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env	*find_add_env(char *key)
{
	t_env	*cur;

	cur = g_global.env_lst;
	while (ft_strcmp(cur->key, key) != 0 && cur->next != 0)
		cur = cur->next;
	if (ft_strcmp(cur->key, key) != 0 && cur->next == 0)
	{
		cur->next = add_env(key);
		return (cur->next);
	}
	return (cur);
}

void	change_pwd_env(char *pwd)
{
	t_env	*pwd_env;
	t_env	*old_pwd_env;

	pwd_env = find_add_env("PWD");
	old_pwd_env = find_add_env("OLDPWD");
	if (old_pwd_env->value)
		free(old_pwd_env->value);
	old_pwd_env->value = pwd_env->value;
	if (pwd)
		pwd_env->value = ft_strdup(pwd);
	else
		pwd_env->value = ft_strdup("");
	if (!pwd_env->value)
	{
		ft_putstr_fd("memory error\n", 2);
		g_global.exit_code = 1;
	}
}

void	ft_cd(t_argv *node)
{
	int		error;
	char	*err_msg;
	char	*next_dir;
	char	pwd[MAX_BUF];
	t_env	*home;

	next_dir = node->cmd[1];
	home = find_env("HOME");
	if ((!node->cmd[1] && home) || ft_strcmp(node->cmd[1], "~") == 0)
		next_dir = home->value;
	error = chdir(next_dir);
	if (error || !getcwd(pwd, MAX_BUF))
	{
		if (!node->cmd[1])
			err_msg = "minishell: cd: HOME not set\n";
		else
			err_msg = "minishell: cd: No such file or directory\n";
		ft_putstr_fd(err_msg, 2);
		g_global.exit_code = 1;
	}
	change_pwd_env(pwd);
	g_global.exit_code = 0;
}
