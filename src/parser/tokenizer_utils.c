/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:01:41 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 15:01:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	quote_state(char c, t_state *state)
{
	if (c == DOUBLE_QUOTE && state->qoute == false)
	{
		if (state->double_quote == true)
			state->double_quote = false;
		else
			state->double_quote = true;
		return (1);
	}
	if (c == QOUTE && state->double_quote == false)
	{
		if (state->qoute == true)
			state->qoute = false;
		else
			state->qoute = true;
		return (1);
	}
	return (0);
}

t_bool	quote_check(t_state *state)
{
	return (!state->double_quote && !state->qoute);
}
