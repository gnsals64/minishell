/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:25:19 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 16:25:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_node	*ft_lst_new(char type, char *s)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->str = ft_strdup(s);
	node->type = type;
	if (!(node->str))
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

char	ft_find_special(char c1, char c2)
{
	if (c1 == '<' && c2 == '<')
		return (HERE_DOC);
	if (c1 == '>' && c2 == '>')
		return (DREDIR_OUT);
	return (c1);
}

int	ft_find_substr_len(char *s, int i, char *type, t_data *data)
{
	int		len;
	t_state	state;
	char	c;

	(void)data;
	ft_memset(&state, 0, sizeof(state));
	len = 0;
	c = ft_find_special(s[i], s[i + 1]);
	*type = ft_isspecial(c);
	if (ft_isspecial(c) != 0)
	{
		if (*type == HERE_DOC || *type == DREDIR_OUT)
			return (2);
		return (1);
	}
	while (s[i] && !(quote_check(&state) && ft_isspecial(s[i])))
	{
		quote_state(s[i], &state);
		i++;
		len++;
	}
	return (len);
}
