#! Commands
NAME = push_swap
CC = cc
RM = rm -f
AR = ar -rc

#! Flags
CFLAGS = -Wall -Wextra -Werror


PUSH_SWAP = push_swap.c check.c lists.c error_handler.c rules.c rules_both.c init_stack.c sorting_small.c sorting_big.c put_everything_back.c
UTILS = ./utils/libftprintf.a

PUSH_SWAP_OBJS = $(PUSH_SWAP:.c=.o)

#! Rules

all: $(NAME)


$(UTILS):
	make -C ./utils

$(NAME): $(UTILS) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(UTILS) -o $(NAME)


clean:
	$(RM) $(PUSH_SWAP_OBJS)
	make clean -C ./utils

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./utils

re: fclean all