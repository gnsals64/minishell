/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:19:45 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 14:19:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	find_split_len(char *str)
{
	int		i;
	int		len;
	t_state	state;

	i = 0;
	len = 0;
	ft_memset(&state, 0, sizeof(t_state));
	while (str[i])
	{
		quote_state(str[i], &state);
		if (quote_check(&state) && str[i] != ' '
			&& (str[i + 1] == ' ' || str[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

int	ft_dup_line_len(char *str, int **index)
{
	int		len;
	t_state	state;

	len = 0;
	ft_memset(&state, 0, sizeof(state));
	while (str[**index] && !(quote_check(&state) && str[**index] == ' '))
	{
		if (quote_state(str[**index], &state) == 0)
			len++;
		(**index)++;
	}
	(**index)++;
	return (len);
}

char	*ft_dup_line(char *str, int *index)
{
	char	*tmp;
	int		i;
	int		len;
	int		start;
	t_state	state;

	i = 0;
	len = 0;
	start = *index;
	ft_memset(&state, 0, sizeof(state));
	len = ft_dup_line_len(str, &index);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		if (quote_state(str[start], &state) == 0)
		{
			tmp[i] = str[start];
			i++;
		}
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**ft_tokenizer(char *str)
{
	char	**save;
	int		len;
	int		j;
	int		i;

	i = 0;
	j = 0;
	len = find_split_len(str);
	save = (char **)malloc(sizeof(char *) * (len + 1));
	if (!save)
		return (NULL);
	while (i < len)
	{
		save[i] = ft_dup_line(str, &j);
		// if (!save[i])
		// 	ft_free_line(save, i);
		i++;
	}
	save[len] = NULL;
	return (save);
}
