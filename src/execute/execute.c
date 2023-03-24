/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:52:07 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/25 02:28:57 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_pipe(t_argv *node)
{
	int	i;

	i = -1;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	single_process(t_argv *node)
{
	int	tmp_stdin_fd;
	int	tmp_stdout_fd;

	tmp_stdin_fd = dup(STDIN_FILENO);
	tmp_stdout_fd = dup(STDOUT_FILENO);
	if (node && node->cmd)
	{
		if (is_builtin(node->cmd[0]) && !node->next)
			single_builtin(node);
		else if (node)
			ft_fork(node, 0);
	}
	else if(node && !node->cmd)
		ft_redirect(node->dir_head);
	dup2(tmp_stdin_fd, STDIN_FILENO);
	dup2(tmp_stdout_fd, STDOUT_FILENO);
}

void	execute(t_argv	*node)
{
	int	pipe_cnt;

	pipe_cnt = check_pipe(node);
	/*
	heredoc처리 먼저 해야함
	if (check_here_doc(node))
		return ;
	*/
	if (pipe_cnt == 0)
		single_process(node);
	else
		ft_fork(node, pipe_cnt);
}
