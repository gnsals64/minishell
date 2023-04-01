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

void	dir_error_message(int a, t_data *data, t_redirect **node)
{
	if (a == 1)
	{
		free((*node)->operator);
		free(*node);
		ft_putstr_fd("syntax error near unexpected token 'newline' \n", 2);
		g_global.exit_code = 258;
	}
	else if (a == 2)
	{
		free((*node)->operator);
		free((*node)->filename);
		free(*node);
		ft_putstr_fd("minishell: syntax error near unexpected token \'", 2);
		ft_putstr_fd(data->move->str, 2);
		ft_putstr_fd("\'\n", 2);
		g_global.exit_code = 258;
	}
}

int	ft_creat_argv(t_data *data, int *i)
{
	if (data->move == NULL)
		return (-1);
	else if (data->move->type == WORD)
		argv_word(data, i);
	else if (data->move->type != WORD && data->move->type != PIPE_LINE)
	{
		if (argv_dir(data) == -1)
			return (-2);
	}
	else if (data->move->type == PIPE_LINE)
	{
		if (data->move->next == NULL || data->move->next->type == PIPE_LINE)
		{
			ft_putstr_fd("syntax error near unexpected token '|'\n", 2);
			g_global.exit_code = 258;
			return (-2);
		}
		argv_pipe(data, i);
		return (-1);
	}
	return (0);
}

int	ft_merge_data(t_data *data, int *i)
{
	int	status;

	status = 0;
	data->argv_head = (t_argv *)malloc(sizeof(t_argv));
	if (!data->argv_head)
		ft_exit_parsing_error(data);
	ft_memset(data->argv_head, 0, sizeof(t_argv));
	data->argv_cur = data->argv_head;
	while (status != -1)
	{
		status = ft_creat_argv(data, i);
		if (status == -2)
			return (-1);
	}
	return (0);
}

int	ft_merge_data_next(t_data *data, int *i)
{
	int	status;

	status = 0;
	data->argv_cur->next = (t_argv *)malloc(sizeof(t_argv));
	if (!data->argv_cur->next)
		ft_exit_parsing_error(data);
	ft_memset(data->argv_cur->next, 0, sizeof(t_argv));
	data->argv_cur = data->argv_cur->next;
	while (status != -1)
	{
		status = ft_creat_argv(data, i);
		if (status == -2)
			return (-1);
	}
	return (0);
}

int	make_argv(t_data *data)
{
	int	i;

	i = 0;
	while (data->move != NULL)
	{
		if (!data->argv_head)
		{
			if (ft_merge_data(data, &i) == -1)
				return (-1);
		}
		else
		{
			if (ft_merge_data_next(data, &i) == -1)
				return (-1);
		}
	}
	data->argv_cur = data->argv_head;
	return (0);
}
