/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:33:27 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/31 13:57:41 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	open_tmp_stdin(t_redirect *redir, int *flag)
{
	int	infile_fd;

	if (! redir->filename)
	{
		*flag = 1;
		return (-1);
	}
	if (ft_strcmp(redir->operator, "<") == 0)
		infile_fd = open(redir->filename, O_RDONLY, 0644);
	if (ft_strcmp(redir->operator, "<<") == 0)
		infile_fd = redir->fd;
	if (infile_fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(redir->filename, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		*flag = 1;
		return (-1);
	}
	return (infile_fd);
}

int	open_tmp_stdout(t_redirect *redir, int *flag, int outfile_fd)
{
	if (outfile_fd != -1)
		close(outfile_fd);
	if (ft_strcmp(redir->operator, ">") == 0)
		outfile_fd = open(redir->filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (ft_strcmp(redir->operator, ">>") == 0)
		outfile_fd = open(redir->filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (outfile_fd == -1)
	{
		*flag = 1;
		return (-1);
	}
	return (outfile_fd);
}

void	check_dup_fd(int infile_fd, int outfile_fd, int flag)
{
	if (!flag && infile_fd != -1)
	{
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
	}
	if (!flag && outfile_fd != -1)
	{
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
	}
	return ;
}

int	ft_redirect(t_redirect *redir)
{
	int	outfile_fd;
	int	infile_fd;
	int	flag;

	outfile_fd = -1;
	infile_fd = -1;
	flag = 0;
	while (redir)
	{
		if (ft_strcmp(redir->operator, "<") == 0 || \
		ft_strcmp(redir->operator, "<<") == 0)
			infile_fd = open_tmp_stdin(redir, &flag);
		if (ft_strcmp(redir->operator, ">") == 0 || \
		ft_strcmp(redir->operator, ">>") == 0)
			outfile_fd = open_tmp_stdout(redir, &flag, outfile_fd);
		redir = redir->next;
	}
	check_dup_fd(infile_fd, outfile_fd, flag);
	if (flag == 1)
		return (1);
	return (0);
}
