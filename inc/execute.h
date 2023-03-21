/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:14:19 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/21 19:38:40 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define MAX_BUF 4096

//builtin_utils.c
int		ft_strcmp(const char *s1, const char *s2);
t_env	*add_env(char *key);
t_env	*set_add_env(char *key);
//ft_cd.c
void	ft_cd(t_argv *node);
//fd_echo.c
void	ft_echo(t_argv *node);
//ft_env.c
void	ft_env(t_argv *node);
//ft_exit.c

//ft_export.c
void	ft_export(t_argv *node);
//ft_pwd.c
void	ft_pwd(void);
//ft_unset.c

//execute
void	execute(t_argv	*node);
void	single_process(t_argv *node);
int		check_pipe(t_argv *node);
void	ft_fork(t_argv *node, int pipe_cnt);
void	pipe_generate(t_argv *node, int pipe_cnt, int pipes[2][2]);
void	child_process(t_argv *node, int i, int pipe_cnt, int pipes[2][2]);
void	wait_process(int pipe_cnt);
int		is_builtin(char *cmd);
void	ft_error(char *s, int exit_code);

#endif
