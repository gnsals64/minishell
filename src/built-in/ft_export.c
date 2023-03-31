/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:22 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/31 13:59:39 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_export_env(void)
{
	t_env	*cur;

	cur = g_global.env_lst;
	while (cur)
	{
		printf("declare -x %s", cur->key);
		if (cur->value)
			printf("=\"%s\"", cur->value);
		printf("\n");
		cur = cur->next;
	}
	g_global.exit_code = 0;
}

char	**find_key_value(char *arg)
{
	char	**result;
	int		i;

	if (!ft_strchr(arg, '='))
	{
		result = (char **)malloc(sizeof(char *) * 2);
		if (!result)
			ft_error("malloc error", 1);
		result[0] = ft_strdup(arg);
		result[1] = NULL;
		return (result);
	}
	result = (char **)malloc(sizeof(char *) * 3);
	if (!result)
		ft_error("malloc error", 1);
	i = ft_strchr(arg, '=') - arg;
	result[0] = (char *)malloc(sizeof(char) * i + 1);
	if (!result[0])
		ft_error("malloc error", 1);
	ft_strlcpy(result[0], arg, i + 1);
	result[1] = ft_strdup(arg + i + 1);
	result[2] = NULL;
	return (result);
}

int	is_valid_name(char *key, char *all)
{
	int	i;

	i = -1;
	if ((!ft_isalpha(key[++i]) && key[i] != '_'))
	{
		ft_identifier_error(all);
		g_global.exit_code = 1;
		return (0);
	}
	while (key[++i])
	{
		if (!ft_isalpha(key[i]) && !ft_isdigit(key[i]) && \
			key[i] != '_')
		{
			ft_identifier_error(all);
			g_global.exit_code = 1;
			return (0);
		}
	}
	g_global.exit_code = 0;
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

void	ft_export(t_argv *node)
{
	t_env	*cur;
	char	**argument;
	int		i;

	if (!node->cmd[1])
	{
		print_export_env();
		return ;
	}
	i = 1;
	while (node->cmd[i])
	{
		argument = find_key_value(node->cmd[i]);
		if (is_valid_name(argument[0], node->cmd[i]))
		{
			cur = set_add_env(argument[0]);
			if (argument[1] != 0)
			{
				free(cur->value);
				cur->value = ft_strdup(argument[1]);
			}
		}
		double_free_arg(argument);
		i++;
	}
}
