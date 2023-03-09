/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:22 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/09 22:48:18 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_export_env(t_env *env)
{
	t_env	*cur;

	cur = env;
	while (cur != NULL)
	{
		printf("declare -x %s", env->key);
		if (env->value)
			printf("=\"%s\"", env->value);
		printf("\n");
		env = env->next;
	}
}

char	**find_key_value(char *arg)
{
	char **result;
	int i;

	if (!ft_strchr(arg, '='))
	{
		result = (char **)malloc(sizeof(char *) * 2);
		if (!result)
		{
			printf("malloc error\n");
			return ;
		}
		result[0] = ft_strdup(arg);
		result[1] = NULL;
		return (result);
	}
	result = (char **)malloc(sizeof(char *) * 3);
	if (!result)
	{
		printf("malloc error\n");
		return ;
	}
	i = ft_strchr(arg, '=') - arg;
	result[0] = (char *)mallog(sizeof(char) * i + 1);
	if (!result[0])
	{
		printf("malloc error\n");
		return ;
	}
	ft_strlcpy(result[0], arg, i + 1);
	result[1] = ft_strdup(arg + i + 1);
	result[2] = NULL;
	return (result);
}

int	is_valid_name(char *key, char *all)
{
	int	i;

	i = -1;
	if (!ft_isalpha(key[++i]) || key[i] != '_')
	{
		printf("export: `%s': not a valid identifier\n", all);
		return (0);
	}
	while (key[++i])
	{
		if (!ft_isalpha(key[i]) || !ft_isdigit(key[i]) || \
			key[i] != '_')
		{
			printf("export: `%s': not a valid identifier\n", all);
			return (0);
		}
	}
	return (1);
}

void	double_free_arg(char **argument)
{
	int	i;

	i = -1;
	while (argument && argument[++i])
		free(argument[i]);
	free(argument);
}

void	ft_export(t_node *node, t_env *env)
{
	t_env	*cur;
	char	**argument;
	int		i;

	if (!node->cmd[1])
	{
		print_export_env(env);
		return ;
	}
	i = 0;
	while (node->cmd[++i])
	{
		argument = find_key_value(node->cmd[i]);
		if (is_valid_name(argument[0], node->cmd[i]))
		{
			cur = set_add_env(env, argument[0]);
			if (argument[1])
			{
				free(cur->value);
				cur->value = ft_strdup(argument[1]);
			}
		}
		double_free_env(argument);
	}
}
