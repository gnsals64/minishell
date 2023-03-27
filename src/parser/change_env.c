/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 02:10:22 by marvin            #+#    #+#             */
/*   Updated: 2023/03/20 02:10:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_change_str_len(char *str, t_data *data)
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
		if (str[i] == '$' && state.qoute == false)
		{
			tmp = ft_strndup(&str[i + 1], ft_envlen(&str[i + 1], &state));
			if (!tmp)
				ft_exit_parsing_error(data);
			i += ft_strlen(tmp) + 1;
			len += ft_strlen(ft_find_env(tmp, data));
			free(tmp);
			continue ;
		}
		len++;
		i++;
	}
	return (len);
}

void	env_cat(t_env_var *var, t_data *data, t_state *state, char *str)
{
	char	*tmp;

	tmp = ft_strndup(&str[var->j + 1], ft_envlen(&str[var->j + 1], state));
	if (!tmp)
		ft_exit_parsing_error(data);
	var->j += ft_strlen(tmp) + 1;
	ft_strlcat(var->change_str, ft_find_env(tmp, data),
		ft_strlen(var->change_str) + ft_strlen(ft_find_env(tmp, data)) + 1);
	var->i = ft_strlen(var->change_str);
	free(tmp);
}

char	*change_env_dup(char *str, t_data *data, int len, t_state *state)
{
	t_env_var	var;

	ft_memset(&var, 0, sizeof(t_env_var));
	var.change_str = calloc(sizeof(char), len + 1);
	if (!var.change_str)
		ft_exit_parsing_error(data);
	while (str[var.j])
	{
		quote_state(str[var.j], state);
		if (str[var.j] == '$' && state->qoute == false)
		{
			env_cat(&var, data, state, str);
			continue ;
		}
		var.change_str[var.i] = str[var.j];
		var.i++;
		var.j++;
	}
	return (var.change_str);
}

char	*ft_load_exitcode(char *str, t_data *data)
{
	char	*change_str;
	t_state	state;
	int		len;

	while (ft_isspace(*str) == 1 && *str != '\0')
		str++;
	ft_memset(&state, 0, sizeof(t_state));
	len = ft_change_str_exitcode_len(str);
	if (len == -1)
	{
		write(2, "close the quote\n", 16);
		return (NULL);
	}
	change_str = change_exitcode(str, data, len, &state);
	return (change_str);
}

char	*ft_change_str(char *str, t_data *data)
{
	char	*change_str;
	t_state	state;
	int		len;

	len = ft_change_str_len(str, data);
	ft_memset(&state, 0, sizeof(t_state));
	change_str = change_env_dup(str, data, len, &state);
	free(str);
	return (change_str);
}
