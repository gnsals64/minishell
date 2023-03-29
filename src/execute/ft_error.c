/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:42:30 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/29 20:05:22 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_cmd_error(char *s)
{
	ft_putstr_fd("bash: ", 2);
	if (s != 0 && *s != 0)
		ft_putstr_fd(s, 2);
	ft_putstr_fd(": command not found\n", 2);
	g_global.exit_code = 127;
	exit (127);
}

void	ft_identifier_error(char *s)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

void	ft_error(char *s, int exit_code)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(exit_code);
}
