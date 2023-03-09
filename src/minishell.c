/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:32:12 by hunpark           #+#    #+#             */
/*   Updated: 2023/03/09 10:43:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	run_program(t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline("input> ");
		if (ft_parsing(line, data) == 0)
		{
			printf("ouput> %s\n", line);
			add_history(line);
			free(line);
			line = NULL;
		}
		else
			printf("Ctrl + d\n");
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	(void)av;
	if (ac != 1 || !*env)
		return (1);
	data = ft_init(env);
	if (!data)
		return (1);
	run_program(data);
}
