/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:46:40 by hunpark           #+#    #+#             */
/*   Updated: 2023/03/29 23:34:49 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_env	*env_node_creat(char *env)
{
	t_env	*node;
	int		len;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->value = ft_strdup(ft_strchr(env, '=') + 1);
	len = ft_strlen(env) - ft_strlen(node->value) - 1;
	node->key = ft_substr(env, 0, len);
	if (!node->value || !node->key)
		return (NULL);
	node->next = NULL;
	return (node);
}

int	ft_env_creat(t_data *data, char *env)
{
	t_env	*node;

	if (!env)
		return (0);
	node = env_node_creat(env);
	if (!node)
		ft_exit_parsing_error(data);
	if (!data->env)
	{
		data->env = node;
		data->env_head = data->env;
	}
	data->env->next = node;
	if (!data->env->next)
		ft_exit_parsing_error(data);
	data->env = data->env->next;
	return (0);
}
