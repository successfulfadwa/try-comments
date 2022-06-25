NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC =	ft_atoi.c \
		ft_atol.c \
		ft_isdigit.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
