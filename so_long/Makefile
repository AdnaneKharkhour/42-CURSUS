NAME = so_long

SRC = main.c map.c load_images.c render_map.c utils.c map_checker.c map_checker_2.c map_checker_3.c controls.c \
	 LIBFT/GET_NEXT_LINE/get_next_line.c LIBFT/GET_NEXT_LINE/get_next_line_utils.c \
	 LIBFT/FT_PRINTF/ft_printf.c LIBFT/FT_PRINTF/ft_putchar.c LIBFT/FT_PRINTF/ft_putnbr.c LIBFT/FT_PRINTF/ft_putstr.c \
	 LIBFT/libft/ft_calloc.c LIBFT/libft/ft_memset.c

SRC_BONUS = bonus/main_bonus.c bonus/map_bonus.c bonus/load_images_bonus.c bonus/enemy_bonus.c bonus/render_map_bonus.c bonus/utils_bonus.c bonus/map_checker_bonus.c bonus/map_checker_2_bonus.c bonus/map_checker_3_bonus.c bonus/controls_bonus.c \
	 LIBFT/GET_NEXT_LINE/get_next_line.c LIBFT/GET_NEXT_LINE/get_next_line_utils.c \
	 LIBFT/FT_PRINTF/ft_printf.c LIBFT/FT_PRINTF/ft_putchar.c LIBFT/FT_PRINTF/ft_putnbr.c LIBFT/FT_PRINTF/ft_putstr.c \
	 LIBFT/libft/ft_calloc.c LIBFT/libft/ft_memset.c

HEADERS = game.h bonus/game_bonus.h LIBFT/GET_NEXT_LINE/get_next_line.h LIBFT/FT_PRINTF/ft_printf.h LIBFT/libft/libft.h

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(SRC_BONUS:.c=.o)

NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX = libmlx.a -framework OpenGL -framework AppKit


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

mandatory: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX) -o $(NAME_BONUS)

bonus : $(NAME_BONUS)

all: $(NAME) $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all mandatory bonus clean fclean re
