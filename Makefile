NAME = push_swap
CHECKER = checker

SRC = main.c \
	  utils.c \
	  stack_utils.c \
	  validation.c \
	  parse_args.c \
	  parse_int.c \
	  index.c \
	  operations.c \
	  rotate_operations.c \
	  reverse_operations.c \
	  sort_small.c \
	  sort_utils.c \
	  turk_algorithm.c \
	  turk_cost.c \
	  turk_target.c \
	  turk_shift.c

SRC_BONUS = checker.c \
			utils.c \
			stack_utils.c \
			validation.c \
			parse_args.c \
			parse_int.c \
			index.c \
			operations.c \
			rotate_operations.c \
			reverse_operations.c

OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(SRC_BONUS:.c=.o)

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

bonus: $(CHECKER)

$(CHECKER): $(OBJ_BONUS)
	@make -C libft
	$(CC) $(OBJ_BONUS) -Llibft -lft -o $(CHECKER)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make clean -C libft/

fclean: clean
	rm -f $(NAME) $(NAME).exe $(CHECKER) $(CHECKER).exe
	make fclean -C libft/

re: fclean all

debug: $(OBJ)
	$(CC) $(CCFLAGS) -fsanitize=address $(OBJ) -Llibft -lft -o $(NAME)

.PHONY: libft clean fclean re debug all bonus
