/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:42:15 by marvin            #+#    #+#             */
/*   Updated: 2023/03/06 19:42:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_argv_cnt(t_data *data)
{
	int		len;
	t_node *tmp;

	len = 0;
	tmp = data->move;
	while (tmp != NULL)
	{
		if (tmp->type == WORD && (tmp->prev == NULL ||
			tmp->prev->type == WORD || tmp->prev->type == PIPE_LINE))
			len++;
		if (tmp->type == PIPE_LINE)
			break ;
		tmp = tmp->next;
	}
	return (len);
}

void	argv_pipe(t_data *data, int *i)
{
	if (data->argv_cur->cmd)
		data->argv_cur->cmd[*i] = NULL;
	data->move = data->move->next;
	*i = 0;
}

t_redirect	*ft_make_dir_node(t_data *data)
{
	t_redirect	*node;

	node = (t_redirect *)malloc(sizeof(t_redirect));
	if (!node)
		return (NULL);
	node->operator = ft_strdup(data->move->str);
	data->move = data->move->next;
	if (data->move == NULL)
		return (node);
	if (data->move->type != WORD)
		return (NULL);
	node->filename = ft_strdup(data->move->str);
	data->move = data->move->next;
	node->next = NULL;
	return (node);
}

void	argv_dir(t_data	*data)
{
	if (!data->argv_cur->dir)
	{
		data->argv_cur->dir = ft_make_dir_node(data);
		data->argv_cur->dir_head = data->argv_cur->dir;
		if (!data->argv_cur->dir)
			return ;
		return ;
	}
	data->argv_cur->dir->next = ft_make_dir_node(data);
	if (!data->argv_cur->dir->next)
			return ;
	data->argv_cur->dir = data->argv_cur->dir->next;
}

void	argv_word(t_data *data, int *i)
{
	int	len;

	if (!data->argv_cur->cmd)
	{
		len = ft_argv_cnt(data);
		data->argv_cur->cmd = (char **)malloc(sizeof(char *) * (len + 1));
		if (!data->argv_cur->cmd)
			return ;
		data->argv_cur->cmd[*i] = ft_strdup(data->move->str);
		if (!data->argv_cur->cmd[*i])
			return ;
		(*i)++;
		data->move = data->move->next;
		return ;
	}
	data->argv_cur->cmd[*i] = ft_strdup(data->move->str);
	if (!data->argv_cur->cmd[*i])
		return ;
	(*i)++;
	data->move = data->move->next;
}

int	ft_creat_argv(t_data *data, int *i)
{
	if (data->move == NULL)
		return (-1);
	else if (data->move->type == WORD)
		argv_word(data, i);
	else if (data->move->type != WORD && data->move->type != PIPE_LINE)
		argv_dir(data);
	else if (data->move->type == PIPE_LINE)
	{
		argv_pipe(data, i);
		return (-1);
	}
	return (0);
}

void	ft_merge_data(t_data *data, int *i)
{
	if (!data->argv_head)
	{
		data->argv_head = (t_argv *)malloc(sizeof(t_argv));
		if (!data->argv_head)
			return ;
		ft_memset(data->argv_head, 0, sizeof(t_argv));
		data->argv_cur = data->argv_head;
		while (ft_creat_argv(data, i) != -1)
			;
		return ;
	}
	data->argv_cur->next = (t_argv *)malloc(sizeof(t_argv));
	if (!data->argv_cur->next)
			return ;
	ft_memset(data->argv_cur->next, 0, sizeof(t_argv));
	data->argv_cur = data->argv_cur->next;
	while (ft_creat_argv(data, i) != -1)
			;
}

void	make_argv(t_data *data)
{
	int	i;

	i = 0;
	while (data->move != NULL)
		ft_merge_data(data, &i);
}
