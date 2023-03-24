/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunaprk <hunaprk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:04:39 by hunpark           #+#    #+#             */
/*   Updated: 2023/03/25 01:53:03 by hunaprk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_token_free(t_data *data)
{
	t_node	*tmp;

	tmp = data->head;
	data->head = data->head->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	free(tmp->str);
	tmp->str = NULL;
	free(tmp);
	tmp = NULL;
}

void	ft_dir_free(t_data *data)
{
	t_redirect	*tmp;

	tmp = data->argv_head->dir_head;
	data->argv_head->dir_head = data->argv_head->dir_head->next;
	free(tmp->filename);
	free(tmp->operator);
	tmp->filename = NULL;
	tmp->operator = NULL;
	tmp->next = NULL;
	free(tmp);
}

void	ft_argv_free(t_data *data)
{
	t_argv	*tmp;
	int		i;

	i = -1;
	tmp = data->argv_head;
	if (tmp->cmd)
	{
		while (tmp->cmd[++i])
			free(tmp->cmd[i]);
	}
	free(tmp->cmd);
	tmp->cmd = NULL;
	while (tmp->dir_head != NULL)
		ft_dir_free(data);
	tmp->dir = NULL;
	tmp->dir_head = NULL;
	data->argv_head = data->argv_head->next;
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
}

void	ft_env_free(t_data *data)
{
	t_env	*tmp;

	tmp = data->env_head;
	data->env_head = data->env_head->next;
	tmp->next = NULL;
	free(tmp->key);
	free(tmp->value);
	tmp->key = NULL;
	tmp->value = NULL;
	free(tmp);
	tmp = NULL;
}

void	ft_free_all(t_data *data)
{
	while (data->head != NULL)
		ft_token_free(data);
	while (data->argv_head != NULL)
		ft_argv_free(data);
}
