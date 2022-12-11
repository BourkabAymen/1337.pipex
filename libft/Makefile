# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 15:28:35 by abourkab          #+#    #+#              #
#    Updated: 2022/10/24 15:30:10 by abourkab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c ft_strchr.c ft_putchar_fd.c \
      ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
      ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_memset.c \
      ft_bzero.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
      ft_isascii.c ft_isdigit.c ft_isalpha.c ft_isalnum.c \
      ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c \
      ft_calloc.c ft_strjoin.c ft_strnstr.c  \
      ft_memchr.c ft_strncmp.c ft_substr.c ft_itoa.c \
      ft_split.c ft_strtrim.c ft_strrchr.c \
      ft_strmapi.c ft_striteri.c

BSRC = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
       ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
       ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
       ft_lstmap_bonus.c

OBJS = ${SRC:.c=.o}
BOBJ = ${BSRC:.c=.o}

INC = libft.h
FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
		ar rsc ${NAME} ${OBJS}

bonus: ${NAME} ${BOBJ}
		ar rsc ${NAME} ${BOBJ}
        
.c.o:
		cc ${FLAGS} -c $< -o ${<:.c=.o} -I ${INC}

clean:
		rm -f ${OBJS} ${BOBJ}

fclean: clean
		rm -f ${NAME}

re:  fclean all
