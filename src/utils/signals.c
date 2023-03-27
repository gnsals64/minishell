/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:25:14 by marvin            #+#    #+#             */
/*   Updated: 2023/03/28 00:22:19 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handler(int signum)
{
	if (signum != SIGINT)
		return ;
	rl_replace_line("", 1);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	heredoc_handler(int signum)
{
	if (signum == SIGINT)
		exit(1);
	ft_putendl_fd("", STDOUT_FILENO);
	exit(0);
}

void	handler_q(int signum)
{
	if (signum != SIGQUIT)
		return ;
	rl_on_new_line();
	rl_redisplay();
}

void	handle_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
