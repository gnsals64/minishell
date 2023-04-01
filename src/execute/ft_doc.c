/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:38:29 by sooyang           #+#    #+#             */
/*   Updated: 2023/04/01 17:34:23 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	manage_doc(char *buf, int fd, int n)
{
	free(buf);
	close(fd);
	if (n == 0)
		exit(1);
	else if (n == 1)
		exit(0);
}

void	here_doc(int fd[2], char *filename)
{
	char	*buf;

	close(fd[0]);
	signal(SIGINT, heredoc_handler);
	while (1)
	{
		buf = readline("> ");
		if (ft_strcmp(buf, filename) == 0)
		{
			write(fd[1], "\0", 1);
			break ;
		}
		if (buf == NULL)
		{
			write(fd[1], "\0", 1);
			break ;
		}
		write(fd[1], buf, ft_strlen(buf));
		write(fd[1], "\n", 1);
		free(buf);
	}
	manage_doc(buf, fd[1], 1);
}

int	create_doc(t_redirect *redir)
{
	int		status;
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1 || !redir->filename)
		ft_error("pipe error", 1);
	pid = fork();
	if (pid == -1)
		ft_error("fork error", 1);
	if (pid == 0)
		here_doc(fd, redir->filename);
	if (pid > 0)
	{
		close(fd[1]);
		wait(&status);
		g_global.exit_code = status >> 8;
		if (status >> 8 == 1)
			return (here_doc_exit(fd[0], redir));
		redir->fd = fd[0];
	}
	return (0);
}

int	ft_doc(t_argv *node, int *flag)
{
	t_redirect	*tmp;

	tmp = node->dir_head;
	while (tmp)
	{
		if (ft_strcmp(tmp->operator, "<<") == 0)
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			*flag = create_doc(tmp);
		}
		if (*flag)
			return (*flag);
		tmp = tmp->next;
	}
	return (*flag);
}

int	check_doc(t_argv *node)
{
	int	flag;

	flag = 0;
	if (!node)
		return (0);
	while (node)
	{
		if (node->dir_head != NULL)
			ft_doc(node, &flag);
		if (flag)
			return (flag);
		node = node->next;
	}
	return (flag);
}
