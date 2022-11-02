# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:46:01 by jtsizik           #+#    #+#              #
#    Updated: 2022/11/02 16:14:25 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	pipex.c \
		pipex_utils.c \
		procs.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_split.c \
		libft/ft_strnstr.c
		
OBJ =	pipex.o \
		pipex_utils.o \
		procs.o \
		ft_strjoin.o \
		ft_strlen.o \
		ft_split.o \
		ft_strnstr.o 

HEADERS =	pipex.h \
			libft/libft.h

${NAME}:
	cc -Wall -Wextra -Werror -c ${SRCS} -I ${HEADERS}
	cc ${OBJ} -o ${NAME}
all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all