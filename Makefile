NAME =		push_swap
CC =		clang
CFLAGS =	-Wall -Werror -Wextra -g
RM =		rm -rf

LIBFT_DIR =	./libft
LIBFT =		$(LIBFT_DIR)/libft.a

SRC_FILES =	push_swap.c \
			init.c \
			validate.c \
			operations.c \
			operations_double.c \
			sort.c \
			sort_simple.c \
			sort_complex.c \
			sort_utils.c \
			movements.c

SRC =		$(addprefix src/, $(SRC_FILES))

OBJECTS =	$(SRC:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJECTS) include/push_swap.h
			$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

clean:
			$(MAKE) -C $(LIBFT_DIR) clean
			$(RM) $(OBJECTS)

fclean:		clean
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re libft
