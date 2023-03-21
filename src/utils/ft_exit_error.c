/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:57:46 by hunpark           #+#    #+#             */
/*   Updated: 2023/03/21 19:28:27 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_exit_parsing_error(t_data *data)
{
	while (data->env_head != NULL)
		ft_env_free(data);
	ft_free_all(data);
	exit(1);
}
