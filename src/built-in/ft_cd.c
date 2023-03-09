/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:10 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/09 23:17:52 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* cd 성공한 뒤에 환경변수 PWD의 값도 변경해야 함 */
void	ft_cd(t_node *node)
{
	char	*path;
	char	pwd[MAX_BUF];

	if (!node->cmd || node->cmd[1] == NULL)
	{
		ft_putstr_fd("argument error\n", 2);
		return ;
	}
	path = node->cmd[1];
	if (chdir(path) == -1 || !getcwd(pwd, MAX_BUF))
	{
		ft_putstr_fd("fail directory change\n", 2);
		return ;
	}
}