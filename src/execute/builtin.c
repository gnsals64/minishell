/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:53:19 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/29 20:11:29 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	single_builtin(t_argv *node)
{
	if (ft_redirect(node->dir))
		return ;
	run_builtin(node);
}

int	run_builtin(t_argv *node)
{
	char	*cmd;

	cmd = node->cmd[0];
	if (ft_strcmp(cmd, "cd") == 0)
		ft_cd(node);
	if (ft_strcmp(cmd, "echo") == 0)
		ft_echo(node);
	if (ft_strcmp(cmd, "env") == 0)
		ft_env(node);
	if (ft_strcmp(cmd, "exit") == 0)
		ft_exit(node);
	if (ft_strcmp(cmd, "export") == 0)
		ft_export(node);
	if (ft_strcmp(cmd, "pwd") == 0)
		ft_pwd();
	if (ft_strcmp(cmd, "unset") == 0)
		ft_unset(node);
	return (0);
}

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	return (0);
}
