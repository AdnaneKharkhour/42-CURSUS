NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = src/main.c src/ft_split_pipex.c src/ft_split_pipex_utils.c src/pipex_utils.c src/utils.c

LIB = utils/libft/libft.a

HEADERS = includes/pipex.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(OBJ)

%.o: %.c HEADERS
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re