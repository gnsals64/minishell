/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:33:20 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/01 20:30:10 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "data_list.h"
# include "execute.h"
# include "../src/libft/libft.h"

//--- parser ---
int			ft_parsing(char *str, t_data *data);
int			quote_state(char c, t_state *state);
int			find_split_len(char *str);
t_bool		quote_check(t_state *state);
char		*ft_dup_line(char *str, int *index);
char		**ft_tokenizer(char *str, t_data *data);
void		ft_free_line(char **save, t_data *data);
char		ft_isspecial(char c);
t_node		*ft_lst_new(char type, char *line);
char		ft_find_special(char c1, char c2);
int			ft_find_substr_len(char *s, int i, char *type, t_data *data);
int			ft_creat_node(char *s, t_data *data);
void		lexer(char **line, t_data *data);
int			ft_save_node(char *tmp, char type, t_data *data);
int			ft_creat_node(char *s, t_data *data);
int			make_argv(t_data *data);
int			ft_merge_data(t_data *data, int *i);
int			ft_merge_data_next(t_data *data, int *i);
int			ft_creat_argv(t_data *data, int *i);
void		argv_word(t_data *data, int *i);
int			argv_dir(t_data	*data);
void		dir_error_message(int a, t_data *data, t_redirect **node);
t_redirect	*ft_make_dir_node(t_data *data);
void		argv_pipe(t_data *data, int *i);
char		*rm_quote(char *str, t_data *data);
char		*ft_single_join(char *s, char c);
int			handle_double_quote(t_data *data, char *str);
int			handle_single_quote(t_data *data, char *str);
int			ft_envlen(char *str, t_state *state);
char		*ft_find_env(char *str, t_data *data);
int			ft_change_str_len(char *str, t_data *data);
char		*change_env_dup(char *str, t_data *data, int len, t_state *state);
char		*ft_change_str(char *str, t_data *data);
void		env_cat(t_env_var *var, t_data *data, t_state *state, char *str);
int			ft_change_str_exitcode_len(char *str);
char		*ft_load_exitcode(char *str, t_data *data);
void		cat_exitcode(t_env_var *var);
char		*change_exitcode(char *str, t_data *data, int len, t_state *state);
void		quote_handle(t_data *data);

//--- utils ---
int			ft_isspace(char c);
char		*ft_strndup(char *str, int n);

//--- env ---
int			ft_env_creat(t_data *data, char *env);
t_env		*env_node_creat(char *env);

//--- free ---
void		ft_token_free(t_data *data);
void		ft_dir_free(t_data *data);
void		ft_argv_free(t_data *data);
void		ft_free_all(t_data *data);
void		ft_env_free(t_data *data);

//--- exit ---
void		ft_exit_parsing_error(t_data *data);

//--- main ---
t_data		*ft_init(char **env);
void		run_program(t_data *data);
void		handler(int signum);
void		heredoc_handler(int signum);
void		handler_q(int signum);
void		child_handler(int signum);
void		handle_terminal(void);

#endif
