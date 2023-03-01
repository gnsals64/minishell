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

# ifndef DATA_LIST_H
#define DATA_LIST_H

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
	HERE_DOC,
	DREDIR_OUT
};

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

typedef struct s_node
{
	char	*str;
	char	type;
	struct s_node *next;
}	t_node;

typedef struct s_data
{
	int				cnt;
	char			**env;
	t_node			*move;
	t_node			*head;
}	t_data;

enum e_token	type;

#endif
