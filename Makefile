NAME = so_long

SRC = main.c map.c load_images.c enemy.c render_map.c utils.c map_checker.c map_checker_2.c map_checker_3.c controls.c libft/get_next_line.c libft/get_next_line_utils.c libft/ft_printf.c libft/ft_putchar.c libft/ft_putnbr.c libft/ft_putstr.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX =  /Users/akharkho/Desktop/libmlx.a -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME): $(OBJ) game.h
	$(CC)  $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -rf $(NAME)
re:fclean all
.PHONY: clean