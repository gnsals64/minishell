/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:48:41 by hunpark           #+#    #+#             */
/*   Updated: 2023/03/21 19:28:29 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	handle_single_quote(t_data *data, char *str)
{
	char	*tmp;

	tmp = ft_strtrim(str, "\'");
	if (!tmp)
		return (-1);
	free(str);
	str = NULL;
	data->move->str = tmp;
	return (0);
}

int	handle_double_quote(t_data *data, char *str)
{
	char	*tmp;

	tmp = ft_strtrim(str, "\"");
	if (!tmp)
		return (-1);
	free(str);
	str = NULL;
	data->move->str = tmp;
	return (0);
}

void	rm_quote(t_data *data)
{
	data->move = data->head;
	while (data->move != NULL)
	{
		if (data->move->str[0] == '\'')
			handle_single_quote(data, data->move->str);
		else if (data->move->str[0] == '\"')
			handle_double_quote(data, data->move->str);
		data->move = data->move->next;
	}
}
