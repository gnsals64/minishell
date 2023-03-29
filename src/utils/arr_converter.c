/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:44:57 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/29 16:30:53 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

size_t	sizeof_list(t_env *envs)
{
	size_t	size;

	size = 0;
	while (envs != NULL)
	{
		envs = envs->next;
		size++;
	}
	return (size);
}

char	**arr_converter(void)
{
	char	*tmp_str;
	char	**arr;
	size_t	size;
	size_t	i;
	t_env	*tmp;

	tmp = g_global.env_lst;
	size = sizeof_list(tmp);
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		ft_error("malloc error", 1);
	arr[size] = 0;
	i = -1;
	while (++i < size && tmp != NULL)
	{
		tmp_str = ft_strjoin(tmp->key, "=");
		arr[i] = ft_strjoin(tmp_str, tmp->value);
		tmp = tmp->next;
	}
	return (arr);
}
