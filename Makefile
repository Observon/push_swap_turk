NAME = push_swap
CHECKER = checker

SRC_COMMON = utils.c \
			stack_utils.c \
			validation.c \
			parse_args.c \
			parse_int.c \
			index.c \
			operations.c \
			rotate_operations.c \
			reverse_operations.c

SRC = main.c \
	  sort_small.c \
	  sort_utils.c \
	  turk_algorithm.c \
	  turk_cost.c \
	  turk_target.c \
	  turk_shift.c \
	  $(SRC_COMMON)

SRC_BONUS = checker_bonus.c \
			$(SRC_COMMON)

OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(SRC_BONUS:.c=.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C libft/

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -I. -Ilibft -c $< -o $@

bonus: $(CHECKER)

$(CHECKER): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(OBJ_BONUS) -Llibft -lft -o $(CHECKER)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make clean -C libft/

fclean: clean
	rm -f $(NAME) $(NAME).exe $(CHECKER) $(CHECKER).exe
	make fclean -C libft/

re: fclean all

.PHONY: libft clean fclean re all bonus
