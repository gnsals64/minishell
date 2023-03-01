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
	while (data->head != NULL)
	{
		printf("node %d : %s\n", i, data->head->str);
		ft_print_type(data->head->type);
		data->head = data->head->next;
		i++;
	}
}
int	ft_parsing(char *str, t_data *data)
{
	char	**line;

	line = ft_tokenizer(str);
	if (!line)
		return (-1);
	lexer(line, data);
	print_node(data);
	return (0);
}
