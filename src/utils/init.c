/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:30:36 by marvin            #+#    #+#             */
/*   Updated: 2023/03/26 23:46:00 by hunpark          ###   ########.fr       */
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
	data->env = NULL;
	data->env_head = NULL;
	while (env[i] != NULL)
	{
		ft_env_creat(data, env[i]);
		i++;
	}
	g_global.env_lst = data->env_head;
	return (data);
}
