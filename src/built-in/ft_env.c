/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:50:40 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/30 01:26:54 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_env(t_argv *node)
{
	t_env	*cursor;

	if (node->cmd[1])
	{
		printf("env: {%s}: No such file or directory\n", node->cmd[1]);
		g_global.exit_code = 127;
		return ;
	}
	cursor = g_global.env_lst;
	while (cursor != NULL)
	{
		if (cursor->value)
			printf("%s=%s\n", cursor->key, cursor->value);
		cursor = cursor->next;
	}
	g_global.exit_code = 0;
}
