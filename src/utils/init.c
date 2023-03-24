/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:30:36 by marvin            #+#    #+#             */
/*   Updated: 2023/03/25 00:14:11 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_data	*ft_init(char **env)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_memset(data, 0, sizeof(data));
	while (env[i] != NULL)
	{
		ft_env_creat(data, env[i]);
		i++;
	}
	g_global.env_lst = data->env_head;

	return (data);
}
