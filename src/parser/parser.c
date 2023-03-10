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

void	ft_print_type(char	c)
{
	if (c == PIPE_LINE)
		printf("type : PIPE_LINE\n\n");
	if (c == ENV)
		printf("type : ENV\n\n");
	if (c == REDIR_IN)
		printf("type : REDIR_IN\n\n");
	if (c == REDIR_OUT)
		printf("type : REDIR_OUT\n\n");
	if (c == HERE_DOC)
		printf("type : HERE_DOC\n\n");
	if (c == DREDIR_OUT)
		printf("type : DREDIR_OUT\n\n");
	if (c == 0)
		printf("type : str\n\n");
}

void	print_node(t_data *data)
{
	int	i;

	i = 0;
	while (data->argv_head != NULL)
	{
		printf("node %d\n\n", i);
		for (int j = 0; data->argv_head->cmd[j] != NULL ; j++)
			printf("argv[%d] = %s\n", j, data->argv_head->cmd[j]);
		printf("\n");
		while(data->argv_head->dir_head != NULL)
		{
			printf("op : %s, filename : %s\n", data->argv_head->dir_head->operator, data->argv_head->dir_head->filename);
			data->argv_head->dir_head = data->argv_head->dir_head->next;
		}
		printf("\n");
		data->argv_head = data->argv_head->next;
		i++;
	}
}

int	ft_parsing(char *str, t_data *data)
{
	char	**line;
	int		i;

	i = -1;
	line = ft_tokenizer(str);
	if (!line)
		return (-1);
	lexer(line, data);
	while (line[++i])
		free(line[i]);
	free(line);
	data->move = data->head;
	make_argv(data);
	//print_node(data);
	return (0);
}
