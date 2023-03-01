/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:25:14 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 14:25:14 by marvin           ###   ########.fr       */
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
