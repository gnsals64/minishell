/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:10:43 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 15:10:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_reset(t_data *data)
{
	data->argv_cur = NULL;
	data->argv_head = NULL;
	data->move = NULL;
	data->head = NULL;
}

int	ft_parsing(char *str, t_data *data)
{
	char	**line;
	int		i;
	char	*load_env;

	i = -1;
	ft_reset(data);
	load_env = ft_load_exitcode(str, data);
	if (!load_env)
		return (-1);
	load_env = ft_change_str(load_env, data);
	line = ft_tokenizer(load_env, data);
	free(load_env);
	lexer(line, data);
	while (line[++i])
		free(line[i]);
	free(line);
	if (make_argv(data) == -1)
	{
		ft_free_all(data);
		return (-1);
	}
	quote_handle(data);
	data->argv_cur = data->argv_head;
	return (0);
}
