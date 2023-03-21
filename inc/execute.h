/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:14:19 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/19 14:37:48 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define MAX_BUF 4096

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_info
{
	struct s_env	*env_lst;
	int				exit_code;
}	t_info;

extern t_info	g_global;

//builtin_utils.c
int		ft_strcmp(const char *s1, const char *s2);
t_env	*add_env(char *key);
t_env	*set_add_env(char *key);
//ft_cd.c
void	ft_cd(t_node *node);
//fd_echo.c
void	ft_echo(t_node *node);
//ft_env.c
void	ft_env(t_node *node, t_env *env);
//ft_exit.c

//ft_export.c
void	ft_export(t_node *node);
//ft_pwd.c
void	ft_pwd(void);
//ft_unset.c


#endif