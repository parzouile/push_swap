# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 23:35:16 by aschmitt          #+#    #+#              #
#    Updated: 2024/01/24 15:26:53 by aschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
NAMEBONUS		= checker

INC				= inc/
SRC_DIR			= srcs/
OBJ_DIR			= obj/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I
RM				= rm -f

SRC 			= $(SRC_DIR)aux_stack.c  $(SRC_DIR)big_sort.c  $(SRC_DIR)find_target.c  $(SRC_DIR)little_sort.c $(SRC_DIR)ft_atoi.c $(SRC_DIR)ft_lst.c  $(SRC_DIR)ft_split.c  $(SRC_DIR)prepare_push_a.c \
				$(SRC_DIR)prepare_push_b.c  $(SRC_DIR)push.c  $(SRC_DIR)push_swap.c  $(SRC_DIR)reverse_rotate.c  $(SRC_DIR)rotate.c  $(SRC_DIR)swap.c $(SRC_DIR)ft_putstr.c

SRCBONUS		= $(SRC_DIR)gnl_utils_bonus.c $(SRC_DIR)gnl_bonus.c $(SRC_DIR)aux_stack.c  $(SRC_DIR)big_sort.c  $(SRC_DIR)find_target.c  $(SRC_DIR)little_sort.c $(SRC_DIR)ft_atoi.c $(SRC_DIR)ft_lst.c  $(SRC_DIR)ft_split.c  $(SRC_DIR)prepare_push_a.c \
				$(SRC_DIR)prepare_push_b.c  $(SRC_DIR)push.c $(SRC_DIR)execute_bonus.c $(SRC_DIR)checker_bonus.c  $(SRC_DIR)reverse_rotate.c  $(SRC_DIR)rotate.c  $(SRC_DIR)swap.c $(SRC_DIR)ft_putstr.c 


OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
OBJBONUS 		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCBONUS))

all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(CC) -o $(NAME) $(OBJ)

bonus: 			$(NAMEBONUS)

$(NAMEBONUS): 	$(OBJBONUS)
				@$(CC) -o $(NAMEBONUS) $(OBJBONUS)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				@$(RM) -r $(OBJ_DIR)

fclean: 		clean
				@$(RM) $(NAME)  $(NAMEBONUS) 

re: 			fclean all

.PHONY: 		all clean fclean re