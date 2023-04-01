/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:25:14 by marvin            #+#    #+#             */
/*   Updated: 2023/04/01 17:36:07 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handler(int signum)
{
	if (signum != SIGINT)
		return ;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
	g_global.exit_code = 1;
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

void	child_handler(int signum)
{
	if (signum != SIGINT | signum != SIGQUIT)
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
