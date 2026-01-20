NAME = push_swap

SRC = main.c \
	  utils.c \
	  validation.c \
	  parse_args.c \
	  index.c \
	  operations.c \
	  reverse_operations.c \
	  sort_small.c \
	  turk_algorithm.c \
	  turk_cost.c \
	  turk_target.c \
	  turk_shift.c

OBJ := $(SRC:.c=.o)

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

libft:
	@make -C libft/

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(OBJ) -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -I. -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME).exe
	make fclean -C libft/

re: fclean all

debug: $(OBJ)
	$(CC) $(CCFLAGS) -fsanitize=address $(OBJ) -Llibft -lft -o $(NAME)

.PHONY: libft clean fclean re debug all
