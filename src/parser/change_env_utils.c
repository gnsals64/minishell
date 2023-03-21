/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 02:11:06 by marvin            #+#    #+#             */
/*   Updated: 2023/03/20 02:11:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_envlen(char *str, t_state *state)
{
	int	i;

	i = 0;
	while (*str != ' ' && *str != '\n')
	{
		if (*str == 0)
			return (i);
		if (state->double_quote == true && *str == '\"')
			return (i);
		i++;
		str++;
	}
	return (i);
}

char	*ft_find_env(char *str, t_data *data)
{
	t_env	*cur;

	cur = data->env_head;
	while (cur != NULL)
	{
		if (ft_strncmp(str, cur->key, ft_strlen(cur->key)) == 0)
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}
