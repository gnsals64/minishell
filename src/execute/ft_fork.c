/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:33:29 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/25 01:34:49 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	wait_process(int pipe_cnt)
{
	int	i;
	int	status;

	i = -1;
	while (++i <= pipe_cnt)
		wait(&status);
}

void	child_process(t_argv *node, int i, int pipe_cnt, int pipes[2][2])
{
	close(pipes[0][0]);
	if (pipe_cnt && i != pipe_cnt)
	{
		dup2(pipes[0][1], STDOUT_FILENO);
		close(pipes[0][1]);
	}
	if (i != 0)
	{
		dup2(pipes[1][0], STDIN_FILENO);
		close(pipes[1][0]);
	}
	if (node->dir_head)
	{
		if (ft_redirect(node->dir_head))
			exit (1);
	}
	if (node->cmd[0] && is_builtin(node->cmd[0]))
		run_builtin(node);
	else
		ft_execute(node);
	exit (0);
}

void	pipe_generate(t_argv *node, int pipe_cnt, int pipes[2][2])
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i <= pipe_cnt)
	{
		if (pipe(pipes[0]) == -1)
			ft_error("pipe error", 1);
		pid = fork();
		if (pid == -1)
			ft_error("fork error", 1);
		if (pid == 0)
			child_process(node, i, pipe_cnt, pipes);
		close(pipes[0][1]);
		if (pid > 0)
		{
			if (i > 0)
				close(pipes[1][0]);
			pipes[1][0] = pipes[0][0];
			if (i == pipe_cnt)
				close(pipes[0][0]);
			node = node->next;
		}
	}
	wait_process(pipe_cnt);
}

void	ft_fork(t_argv *node, int pipe_cnt)
{
	int		pipes[2][2];

	pipe_generate(node, pipe_cnt, pipes);
	return ;
}
