# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 21:41:07 by hunpark           #+#    #+#              #
#    Updated: 2023/03/01 17:18:36 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
FLAG = -Wall -Werror -Wextra
INC = -I ./inc
COMFILE_FLAGS = -lreadline -L$(shell brew --prefix readline)/lib
INCLUDE_FLAGS = -I$(shell brew --prefix readline)/include

PARSER = $(addprefix parser/, parser tokenizer_utils tokenizer lexer isspecial lexer_utils)
FILES = $(addprefix src/, init minishell signals ${UTILS} ${PARSER})

SRCS = ${FILES:=.c}

LIBFT = ./src/libft

all : ${NAME}

${NAME} :
	@make -C ${LIBFT}
	${CC} -g ${FLAG} ${SRCS} ${INC} -lreadline ${LIBFT}/libft.a -o ${NAME}

clean :
	@make clean -C ${LIBFT}
	rm -f bonus

fclean :
	@make fclean -C ${LIBFT}
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
