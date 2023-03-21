/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:32:12 by hunpark           #+#    #+#             */
/*   Updated: 2023/03/21 20:33:49 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_info	g_global;

void	run_program(t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline("input> ");
		if (ft_parsing(line, data) == 0)
		{
			execute(data->argv_cur);
			printf("ouput> %s\n", line);
			add_history(line);
			free(line);
			ft_free_all(data);
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
