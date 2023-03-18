/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:48 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/18 18:52:06 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_env(t_env **env, t_env *tmp_env)
{
	t_env	*del_env;

	del_env = tmp_env->next;
	tmp_env->next = del_env->next;
	free(del_env->key);
	free(del_env->value);
	free(del_env);
}

void	free_last_env(t_env **env, t_env *tmp_env)
{
	t_env	*del_env;

	del_env = tmp_env->next;
	tmp_env->next = 0;
	free(del_env->key);
	free(del_env->value);
	free(del_env);
}

void	free_first_env(t_env **env, t_env *tmp_env)
{
	env = tmp_env->next;
	free(tmp_env->key);
	free(tmp_env->value);
	free(tmp_env);
}

void	ft_unset(t_node *node, t_env **env)
{
	t_env	*tmp_env;
	char	**str;

	str = node->cmd[1];
	while (*str && env)
	{
		tmp_env = env;
		if (tmp_env && ft_strcmp(tmp_env->key, *node->cmd[1]) == 0)
			free_first_env(env, tmp_env);
		else
		{
			while (tmp_env->next && ft_strcmp(tmp_env->next->key, *str))
				tmp_env = tmp_env->next;
			if (!tmp_env->next)
				ft_putstr_fd("not a valid identifier\n", 2);
			else if (!tmp_env->next->next)
				free_last_env(env, tmp_env);
			else
				free_env(env, tmp_env);
		}
		str++;
	}
}