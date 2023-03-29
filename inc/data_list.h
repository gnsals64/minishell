/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:33:02 by marvin            #+#    #+#             */
/*   Updated: 2023/02/26 23:33:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_LIST_H
# define DATA_LIST_H

enum	e_token
{
	WORD = 0,
	WHITE_SPACE = ' ',
	NEW_LINE = '\n',
	QOUTE = '\'',
	DOUBLE_QUOTE = '\"',
	ENV = '$',
	PIPE_LINE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HERE_DOC = 20,
	DREDIR_OUT = 21
};

typedef struct s_env_variable
{
	int		i;
	int		j;
	char	*change_str;
}	t_env_var;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_state
{
	t_bool	qoute;
	t_bool	double_quote;
}	t_state;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_redirect
{
	char				*operator;
	char				*filename;
	int					fd;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_argv
{
	char				**cmd;
	struct s_redirect	*dir;
	struct s_redirect	*dir_head;
	struct s_argv		*next;
}	t_argv;

typedef struct s_node
{
	char			*str;
	char			type;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_data
{
	int				cnt;
	t_env			*env;
	t_env			*env_head;
	t_node			*move;
	t_node			*head;
	t_argv			*argv_head;
	t_argv			*argv_cur;
}	t_data;

typedef struct s_info
{
	struct s_env	*env_lst;
	int				exit_code;
}	t_info;

extern t_info	g_global;

#endif
