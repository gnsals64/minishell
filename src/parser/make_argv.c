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
			ft_exit_parsing_error(data);
		ft_memset(data->argv_head, 0, sizeof(t_argv));
		data->argv_cur = data->argv_head;
		while (ft_creat_argv(data, i) != -1)
			;
		return ;
	}
	data->argv_cur->next = (t_argv *)malloc(sizeof(t_argv));
	if (!data->argv_cur->next)
		ft_exit_parsing_error(data);
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
