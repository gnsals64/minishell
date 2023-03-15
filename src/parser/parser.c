/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:10:43 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 15:10:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_print_type(char	c)
{
	if (c == PIPE_LINE)
		printf("type : PIPE_LINE\n\n");
	if (c == ENV)
		printf("type : ENV\n\n");
	if (c == REDIR_IN)
		printf("type : REDIR_IN\n\n");
	if (c == REDIR_OUT)
		printf("type : REDIR_OUT\n\n");
	if (c == HERE_DOC)
		printf("type : HERE_DOC\n\n");
	if (c == DREDIR_OUT)
		printf("type : DREDIR_OUT\n\n");
	if (c == 0)
		printf("type : str\n\n");
}

void	print_node(t_data *data)
{
	int	i;

	i = 0;
	while (data->argv_head != NULL)
	{
		printf("node %d\n\n", i);
		for (int j = 0; data->argv_head->cmd[j] != NULL ; j++)
			printf("argv[%d] = %s\n", j, data->argv_head->cmd[j]);
		printf("\n");
		while(data->argv_head->dir_head != NULL)
		{
			printf("op : %s, filename : %s\n", data->argv_head->dir_head->operator, data->argv_head->dir_head->filename);
			data->argv_head->dir_head = data->argv_head->dir_head->next;
		}
		printf("\n");
		data->argv_head = data->argv_head->next;
		i++;
	}
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
		if (ft_strncmp(str, cur->key, ft_strlen(str)) == 0)
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}

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

void	ft_change_env_dup(char *str, char **change_str, t_data *data, t_state *state)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[j])
	{
		quote_state(str[j], state);
		if (str[j] == '$' && state->qoute == false)
		{
			tmp = ft_strndup(&str[j + 1], ft_envlen(&str[j + 1], state));
			j += ft_strlen(tmp) + 1;
			*change_str = ft_strjoin(*change_str, ft_find_env(tmp, data));
			i = ft_strlen(*change_str);
			free(tmp);
			continue ;
		}
		(*change_str)[i] = str[j];
		i++;
		j++;
	}
	(*change_str)[i] = '\0';
}

char	*ft_change_str(char *str, t_data *data)
{
	char	*tmp;
	t_state	state;
	int		len;

	len = ft_change_str_len(str, data);
	tmp = ft_calloc(sizeof(char), len + 1);
	if (!tmp)
		return (NULL);
	ft_memset(&state, 0, sizeof(t_state));
	ft_change_env_dup(str, &tmp, data, &state);
	return (tmp);
}

int	ft_parsing(char *str, t_data *data)
{
	char	**line;
	int		i;
	char	*load_env;

	i = -1;
	load_env = ft_change_str(str, data);
	line = ft_tokenizer(load_env);
	if (!line)
		return (-1);
	lexer(line, data);
	while (line[++i])
		free(line[i]);
	free(line);
	data->move = data->head;
	make_argv(data);
	//print_node(data);
	return (0);
}
