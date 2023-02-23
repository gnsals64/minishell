# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 21:41:07 by hunpark           #+#    #+#              #
#    Updated: 2023/02/23 22:48:40 by hunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
FLAG = -Wall -Werror -Wextra
COMFILE_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
INCLUDE_FLAGS = -I${HOME}/.brew/opt/readline/include

SRCS = ./src/minishell.c \

LIBFT = ./libft

all : ${NAME}

${NAME} :
	@make -C ${LIBFT}
	${CC} ${FLAG} ${SRCS} ${COMFILE_FLAGS} ${INCLUDE_FLAGS} ${LIBFT}/libft.a -o ${NAME}

clean :
	@make clean -C ${LIBFT}
	rm -f bonus

fclean :
	@make fclean -C ${LIBFT}
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
