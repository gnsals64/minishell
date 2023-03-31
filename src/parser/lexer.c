/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:34:06 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 15:34:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_save_node(char *tmp, char type, t_data *data)
{
	if (data->head == NULL)
	{
		data->head = ft_lst_new(type, tmp);
		if (!(data->head))
			ft_exit_parsing_error(data);
		data->move = data->head;
		return (0);
	}
	data->move->next = ft_lst_new(type, tmp);
	if (!data->move->next)
		ft_exit_parsing_error(data);
	data->move->next->prev = data->move;
	data->move = data->move->next;
	return (0);
}

int	ft_creat_node(char *s, t_data *data)
{
	char	*tmp;
	int		i;
	int		len;
	char	type;

	i = 0;
	type = 0;
	while (s[i])
	{
		len = ft_find_substr_len(s, i, &type, data);
		tmp = ft_substr(s, i, len);
		if (ft_save_node(tmp, type, data) == -1)
			ft_exit_parsing_error(data);
		free(tmp);
		tmp = NULL;
		i += len;
	}
	return (0);
}

void	lexer(char **line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
		if (ft_creat_node(line[i], data) == -1)
			ft_free_line(line, data);
		i++;
	}
	data->move = data->head;
}
