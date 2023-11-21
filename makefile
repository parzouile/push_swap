# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 17:32:12 by aschmitt          #+#    #+#              #
#    Updated: 2023/11/21 18:22:00 by aschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS = push_swap.c \
			
HEADER = push_swap.h
OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS} 

%.o : %.c ${HEADER} Makefile
	${CC} ${FLAGS}  -I ${HEADER} -o $@ -c $<

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re