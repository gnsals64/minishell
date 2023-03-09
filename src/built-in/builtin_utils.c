/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:46:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/09 23:17:42 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
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
		return ;
	}
	new->key = ft_strdup(key);
	new->value = NULL;
	new->next = NULL;
	return (new);
}

t_env	*set_add_env(t_env *env, char *key)
{
	t_env *cur;

	cur = env;
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