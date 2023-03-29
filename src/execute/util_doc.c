/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:21:05 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/29 23:21:45 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	here_doc_exit(int fd, t_redirect *redir)
{
	redir->fd = 0;
	close(fd);
	write(2, "\n", 1);
	g_global.exit_code = 1;
	return (1);
}
