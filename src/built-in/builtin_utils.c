/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:46:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/04/01 17:35:17 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

t_env	*add_env(char *key)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env) * 1);
	if (!new)
	{
		printf("malloc error\n");
		return (NULL);
	}
	new->key = ft_strdup(key);
	new->value = NULL;
	new->next = NULL;
	return (new);
}

t_env	*set_add_env(char *key)
{
	t_env	*cur;

	cur = g_global.env_lst;
	if (!cur)
	{
		cur = add_env(key);
		return (cur);
	}
	while (ft_strcmp(cur->key, key) && cur->next != NULL)
		cur = cur->next;
	if (ft_strcmp(cur->key, key) && cur->next == NULL)
	{
		cur->next = add_env(key);
		cur = cur->next;
	}
	return (cur);
}

t_env	*find_env(char *key)
{
	t_env	*tmp;

	tmp = g_global.env_lst;
	while (tmp && ft_strcmp(tmp->key, key))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	return (tmp);
}
