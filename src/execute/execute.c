/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:52:07 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/02 14:55:44 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

//middle pipe based, start pipe - end pipe
void	pipe_connected(t_fd *fd)
{
	pid_t	pid;

	if (pipe(fd->fd) == -1)
		print_error("pipe error");
	pid = fork();
	if (pid == -1)
		print_error("fork error");
	if (pid == 0)
		child_process(fd);
	close(fd->fd[1]);
	fd->prev_fd[0] = fd->fd[0];
}


void	execute(int argc, char **argv, char **envp)
{
	t_fd	*fd;
	//파이프의 개수 구하기
	
	pipe_connected(fd);
}