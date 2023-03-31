/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:34:35 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 16:34:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	ft_isspecial(char c)
{
	if (c == PIPE_LINE)
		return (PIPE_LINE);
	if (c == REDIR_IN)
		return (REDIR_IN);
	if (c == REDIR_OUT)
		return (REDIR_IN);
	if (c == HERE_DOC)
		return (HERE_DOC);
	if (c == DREDIR_OUT)
		return (DREDIR_OUT);
	return (0);
}
