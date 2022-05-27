# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 15:55:02 by tjalo             #+#    #+#              #
#    Updated: 2022/05/27 17:04:36 by tjalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -I ./include

HEADER = -I ./include

LIBFTSRC =	lib/ft_split.c \
		lib/ft_strjoin.c \
		lib/ft_strncmp.c \
		lib/ft_strdup.c \
		lib/ft_bzero.c

SRC =	srcs/main.c \
		srcs/utils.c \
		srcs/pipex.c \
		srcs/parse.c \
		${LIBFTSRC}

OBJ = ${SRC:.c=.o}

all:	${NAME}

$(NAME):	${OBJ}
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o%.c:
	${CC} -c ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJ}
	
fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re