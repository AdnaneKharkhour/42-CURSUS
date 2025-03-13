NAME = pipex
CC = cc

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

SRC = src/main.c src/ft_split_pipex.c src/ft_split_pipex_utils.c src/pipex_utils.c src/utils.c utils/libft_pipex/ft_strjoin.c utils/libft_pipex/ft_strncmp.c\
	utils/libft_pipex/ft_strlen.c utils/libft_pipex/ft_memcpy.c

SRC_BONUS = bonus/src/main_bonus.c bonus/src/ft_split_pipex_bonus.c bonus/src/ft_split_pipex_utils_bonus.c bonus/src/pipex_utils_bonus.c bonus/src/utils_bonus.c\
		bonus/src/process_bonus.c bonus/utils/get_next_line_pipex/get_next_line_bonus.c bonus/utils/get_next_line_pipex/get_next_line_utils_bonus.c\
		bonus/utils/libft_pipex/ft_strlen_bonus.c bonus/utils/libft_pipex/ft_memcpy_bonus.c bonus/utils/libft_pipex/ft_strncmp_bonus.c bonus/utils/libft_pipex/ft_strjoin_bonus.c\
		bonus/src/check_args_bonus.c

HEADERS = includes/pipex.h utils/libft_pipex/libft.h
HEADERS_BONUS = bonus/includes/pipex_bonus.h bonus/includes/libft_bonus.h bonus/includes/get_next_line_bonus.h

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@rm -f .bonus
	@rm -f $(OBJ_BONUS)

$(OBJ): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS) .bonus
	
.bonus: $(OBJ_BONUS)
	@touch .bonus
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_BONUS)
	@rm -f $(OBJ)

$(OBJ_BONUS): %.o: %.c $(HEADERS_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	rm -f .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
