/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:48:41 by hunpark           #+#    #+#             */
/*   Updated: 2023/03/31 18:38:20 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	handle_single_quote(t_data *data, char *str)
{
	char	*tmp;

	tmp = ft_strtrim(str, "\'");
	if (!tmp)
		return (-1);
	free(str);
	str = NULL;
	data->move->str = tmp;
	return (0);
}

int	handle_double_quote(t_data *data, char *str)
{
	char	*tmp;

	tmp = ft_strtrim(str, "\"");
	if (!tmp)
		return (-1);
	free(str);
	str = NULL;
	data->move->str = tmp;
	return (0);
}

char	*ft_single_join(char *s, char c)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s);
	tmp = (char *)malloc(sizeof(char) * (len + 2));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s, len + 1);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	free(s);
	return (tmp);
}

char	*rm_quote(char *str, t_data *data)
{
	t_state	state;
	int		i;
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = ft_strdup("");
	if (!tmp)
		ft_exit_parsing_error(data);
	i = 0;
	ft_memset(&state, 0, sizeof(t_state));
	while (str[i])
	{
		if (quote_state(str[i], &state) == 1)
		{
			i++;
			if (str[i] == '\0')
				break ;
		}
		tmp = ft_single_join(tmp, str[i]);
		i++;
	}
	free(str);
	return (tmp);
}
