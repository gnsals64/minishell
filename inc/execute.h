/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:14:19 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/30 01:58:37 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# define MAX_BUF 4096

//builtin_utils.c
int		ft_strcmp(const char *s1, const char *s2);
t_env	*add_env(char *key);
t_env	*set_add_env(char *key);
t_env	*find_env(char *key);
//ft_cd.c
void	ft_cd(t_argv *node);
//fd_echo.c
void	ft_echo(t_argv *node);
//ft_env.c
void	ft_env(t_argv *node);
//ft_exit.c
void	ft_exit(t_argv *node);
//ft_export.c
void	double_free_arg(char **argument);
void	ft_export(t_argv *node);
int		is_valid_name(char *key, char *all);
//ft_pwd.c
void	ft_pwd(void);
//ft_unset.c
void	ft_unset(t_argv *node);
//execute
void	execute(t_argv	*node);
void	single_process(t_argv *node);
int		check_pipe(t_argv *node);
//ft_fork
void	ft_fork(t_argv *node, int pipe_cnt);
void	pipe_generate(t_argv *node, int pipe_cnt, int pipes[2][2]);
void	child_process(t_argv *node, int i, int pipe_cnt, int pipes[2][2]);
void	wait_process(int pipe_cnt);
//builtin
void	single_builtin(t_argv *node);
int		is_builtin(char *cmd);
int		run_builtin(t_argv *node);
//ft_error
void	ft_error(char *s, int exit_code);
void	ft_identifier_error(char *s);
void	ft_cmd_error(char *s);
//ft_execute
void	ft_execute(t_argv *node);
//ft_redirect
int		ft_redirect(t_redirect *redir);
//arr_converter
char	**arr_converter(void);
char	*ft_strjoin2(char const *s1, char const *s2);
//ft_heredoc
void	manage_doc(char *buf, int fd, int n);
void	here_doc(int fd[2], char *filename);
int		create_doc(t_redirect *redir);
int		ft_doc(t_argv *node, int *flag);
int		check_doc(t_argv *node);
int		here_doc_exit(int fd, t_redirect *redir);
#endif
