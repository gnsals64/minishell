# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 21:54:29 by hunpark           #+#    #+#              #
#    Updated: 2023/01/31 10:49:00 by hunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rc
SRCS = ft_isdigit.c ft_strrchr.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	ft_tolower.c ft_toupper.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_split.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

SRCS_BN = ft_lstnew.c		\
		  ft_lstsize.c		\
		  ft_lstadd_front.c	\
		  ft_lstadd_back.c	\
		  ft_lstclear.c		\
		  ft_lstlast.c		\
		  ft_lstiter.c		\
		  ft_lstmap.c		\
		  ft_lstdelone.c	\

OBJS = $(SRCS:.c=.o)

OBJS_BN = $(SRCS_BN:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_BN)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)
	sleep 1

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I .

$(NAME) : $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)

bonus :
	make WITH_BONUS=1 all

clean :
	$(RM) $(OBJS) $(OBJS_BN)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
