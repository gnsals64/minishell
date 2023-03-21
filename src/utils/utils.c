/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:24:47 by marvin            #+#    #+#             */
/*   Updated: 2023/03/19 01:24:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_isspace(char c)
{
	return (c == '\n' || c == ' ' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r');
}

char	*ft_strndup(char *str, int n)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (n + 1));
	if (!tmp)
		return (NULL);
	while (i < n)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
