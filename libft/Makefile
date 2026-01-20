CFLAGS		= -Wall -Wextra -Werror -g
CC			= cc
NAME		= libft.a
FLAGLIB		= -rcs
RM			= rm -f

SRC		= ft_isalpha.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_strdup.c \
		  ft_calloc.c \
		  ft_atoi.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c

SRC_BONUS	= ft_lstnew_bonus.c \
		  ft_lstadd_front_bonus.c \
		  ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c \
		  ft_lstadd_back_bonus.c \
		  ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c \
		  ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c

OBJ		= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) libft.h
			@echo "Gerando $(NAME)"
			@ar $(FLAGLIB) $(NAME) $(OBJ)
			@ranlib $(NAME)

bonus:		$(NAME) $(OBJ_BONUS)
			@echo "Gerando $(NAME) com bonus"
			@ar $(FLAGLIB) $(NAME) $(OBJ_BONUS)
			@ranlib $(NAME)

.c.o:
			@echo "Compilando $(<)"
			@$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
			@$(RM) $(OBJ) $(OBJ_BONUS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean bonus
