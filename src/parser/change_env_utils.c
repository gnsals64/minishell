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

int	ft_change_str_exitcode_len(char *str)
{
	int		i;
	int		len;
	char	*tmp;
	t_state	state;

	i = 0;
	len = 0;
	ft_memset(&state, 0, sizeof(t_state));
	while (str[i])
	{
		quote_state(str[i], &state);
		if (str[i] == '$' && state.qoute == false && str[i + 1] == '?')
		{
			i += 2;
			tmp = ft_itoa(g_global.exit_code);
			len += ft_strlen(tmp);
			free(tmp);
			continue ;
		}
		len++;
		i++;
	}
	if (!quote_check(&state))
		len = -1;
	return (len);
}

void	cat_exitcode(t_env_var *var)
{
	char	*tmp;

	tmp = ft_itoa(g_global.exit_code);
	ft_strlcat(var->change_str, tmp,
		ft_strlen(tmp) + ft_strlen(var->change_str) + 1);
	var->j += 2;
	var->i += ft_strlen(tmp);
	free(tmp);
}

char	*change_exitcode(char *str, t_data *data, int len, t_state *state)
{
	t_env_var	var;

	ft_memset(&var, 0, sizeof(t_env_var));
	var.change_str = calloc(sizeof(char), len + 1);
	if (!var.change_str)
		ft_exit_parsing_error(data);
	while (str[var.j])
	{
		quote_state(str[var.j], state);
		if (str[var.j] == '$' && state->qoute == false && str[var.j + 1] == '?')
		{
			cat_exitcode(&var);
			continue ;
		}
		var.change_str[var.i] = str[var.j];
		var.i++;
		var.j++;
	}
	return (var.change_str);
}
