NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = src/pipex.c
LIB = utils/libft/libft.a
HEADERS = includes/pipex.h
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c HEADERS
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re