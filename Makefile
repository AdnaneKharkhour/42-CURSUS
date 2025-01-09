NAME = so_long

SRC = main.c map.c load_images.c render_map.c utils.c libft/get_next_line.c libft/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX =  libmlx.a -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -rf $(NAME)
re:fclean all
.PHONY: clean