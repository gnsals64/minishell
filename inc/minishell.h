/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:33:20 by hunpark           #+#    #+#             */
/*   Updated: 2023/03/09 04:30:48 by marvin           ###   ########.fr       */
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
# include "data_list.h"
# include "../src/libft/libft.h"

//--- parser ---
int			ft_parsing(char *str, t_data *data);
void		quote_state(char c, t_state *state);
int			find_split_len(char *str);
t_bool		quote_check(t_state *state);
char		*ft_dup_line(char *str, int *index);
char		**ft_tokenizer(char *str);
char		ft_isspecial(char c);
t_node		*ft_lst_new(char type, char *line);
char		ft_find_special(char c1, char c2);
int			ft_find_substr_len(char *s, int i, char *type, t_data *data);
int			ft_creat_node(char *s, t_data *data);
void		lexer(char **line, t_data *data);
int			ft_save_node(char *tmp, char type, t_data *data);
int			ft_creat_node(char *s, t_data *data);
void		make_argv(t_data *data);
void		ft_merge_data(t_data *data, int *i);
int			ft_creat_argv(t_data *data, int *i);
void		argv_word(t_data *data, int *i);
void		argv_dir(t_data	*data);
t_redirect	*ft_make_dir_node(t_data *data);
void		argv_pipe(t_data *data, int *i);

//--- utils ---


//--- main ---
t_data	*ft_init(char **env);
void	run_program(t_data *data);
void	handler(int signum);


#endif
