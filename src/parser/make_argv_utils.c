/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_argv_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:20:45 by hunpark           #+#    #+#             */
/*   Updated: 2023/03/29 22:55:36 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_argv_cnt(t_data *data)
{
	int		len;
	t_node	*tmp;

	len = 0;
	tmp = data->move;
	while (tmp != NULL)
	{
		if (tmp->type == WORD && (tmp->prev == NULL
				|| tmp->prev->type == WORD || tmp->prev->type == PIPE_LINE))
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
	{
		dir_error_message(1, data, &node);
		return (NULL);
	}
	node->filename = ft_strdup(data->move->str);
	if (data->move->type != WORD)
	{
		dir_error_message(2, data, &node);
		return (NULL);
	}
	data->move = data->move->next;
	node->next = NULL;
	return (node);
}

int	argv_dir(t_data	*data)
{
	if (!data->argv_cur->dir)
	{
		data->argv_cur->dir = ft_make_dir_node(data);
		data->argv_cur->dir_head = data->argv_cur->dir;
		if (!data->argv_cur->dir)
			return (-1);
		return (0);
	}
	data->argv_cur->dir->next = ft_make_dir_node(data);
	if (!data->argv_cur->dir->next)
		return (-1);
	data->argv_cur->dir = data->argv_cur->dir->next;
	return (0);
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
		data->argv_cur->cmd[len] = NULL;
		return ;
	}
	data->argv_cur->cmd[*i] = ft_strdup(data->move->str);
	if (!data->argv_cur->cmd[*i])
		return ;
	(*i)++;
	data->move = data->move->next;
}
