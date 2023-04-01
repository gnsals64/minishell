/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:24:09 by sooyang           #+#    #+#             */
/*   Updated: 2023/04/01 17:44:40 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*join_path(char *cmd, char *path)
{
	char	*end_route_of_cmd;
	char	*all_route_of_cmd;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	end_route_of_cmd = ft_strjoin2("/", cmd);
	if (!end_route_of_cmd)
		ft_error("malloc error", 1);
	all_route_of_cmd = ft_strjoin2(path, end_route_of_cmd);
	if (!all_route_of_cmd)
		ft_error("malloc error", 1);
	free(end_route_of_cmd);
	return (all_route_of_cmd);
}

char	*is_valid_path(char *cmd, t_env *env)
{
	char		*path;
	char		**all_path;
	int			i;
	struct stat	status;

	if (!cmd)
		return (NULL);
	all_path = ft_split(env->value, ':');
	i = -1;
	while (all_path[++i])
	{
		path = join_path(cmd, all_path[i]);
		if (stat(path, &status) == 0)
		{
			if (S_ISDIR(status.st_mode))
			{
				ft_putstr_fd(cmd, 2);
				ft_error(": is a directory", 1);
			}
			return (path);
		}
		free(path);
	}
	double_free_arg(all_path);
	return (NULL);
}

char	*is_not_valid_path(char *cmd)
{
	struct stat	status;

	if (stat(cmd, &status) == 0)
	{
		if (S_ISDIR(status.st_mode))
		{
			ft_putstr_fd(cmd, 2);
			ft_error(": is a directory", 1);
		}
		return (cmd);
	}
	ft_putstr_fd(cmd, 1);
	ft_error(" No such file or directory", 1);
	return (NULL);
}

char	*path_finding(char *cmd, int *valid_path)
{
	t_env	*env;
	char	*path;

	if (*cmd == 0 || cmd == 0)
		ft_cmd_error(cmd);
	*valid_path = 0;
	env = find_env("PATH");
	if (env == NULL)
	{
		path = is_not_valid_path(cmd);
		return (path);
	}
	else
	{
		*valid_path = 1;
		path = is_valid_path(cmd, env);
		return (path);
	}
	return (NULL);
}

void	ft_execute(t_argv *node)
{
	char	*path;
	char	**env_arr;
	int		valid_path;

	if (node->cmd == NULL)
	{
		g_global.exit_code = 1;
		exit (1);
	}
	path = path_finding(node->cmd[0], &valid_path);
	env_arr = arr_converter();
	if (execve(path, node->cmd, env_arr) == -1)
		ft_cmd_error(node->cmd[0]);
}
