/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:32:12 by hunpark           #+#    #+#             */
/*   Updated: 2023/02/23 22:21:27 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handler(int signum)
{
	if (signum != SIGINT)
		return ;
	printf("ctrl + c\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

int	main(void)
{
	char	*line;

	signal(SIGINT, handler);
	while (1)
	{
		line = readline("input> ");
		if (line)
		{
			printf("ouput> %s\n", line);
			add_history(line);
			free(line);
			line = NULL;
		}
		else
			printf("Ctrl + d\n");
	}
	return (0);
}
