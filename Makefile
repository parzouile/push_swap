
CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -fsanitize=address

SRCS = aux.c  big_sort.c  find_push.c  ft_split.c  init_cost.c  little_sort.c  prepare_push_b.c  push.c  push_swap.c  reverse_rotate.c  rotate.c  swap.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

TARGET = push_swap

all: ${TARGET}

${TARGET}: ${OBJ}
    ${CC} ${CFLAGS} -o $@ $^

-include ${DEP}

.PHONY: clean

clean:
    ${RM} ${OBJ}
    ${RM} ${DEP}
    ${RM} ${TARGET}