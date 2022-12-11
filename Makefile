# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourkab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 17:32:34 by abourkab          #+#    #+#              #
#    Updated: 2022/12/08 17:34:07 by abourkab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c utils.c
LIBFT = ./libft/libft.a
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MAKE = make
OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: ${LIBFT}
	${CC} ${CFLAGS} ${SRC} ${LIBFT} -o ${NAME}

${LIBFT}:
	${MAKE} -C ./libft; ${MAKE} clean -C ./libft

clean:
	${RM} $(OBJ)
	${MAKE} clean -C libft

fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -C libft 

re: fclean all
