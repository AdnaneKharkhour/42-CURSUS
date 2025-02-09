NAME = push_swap

BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADERS = include/push_swap.h include/checker_bonus.h include/libft.h include/get_next_line.h include/ft_printf.h

SRC = src/push_swap.c src/utils.c src/check_args.c src/sort_less_than_five.c src/sort.c src/moves.c\
	src/r_moves.c utils/LIBFT_PS/ft_atoi.c utils/LIBFT_PS/ft_isdigit.c utils/LIBFT_PS/ft_split.c\
	utils/LIBFT_PS/ft_nodeadd_back.c utils/LIBFT_PS/ft_newnode.c utils/FT_PRINTF_PS/ft_printf.c utils/FT_PRINTF_PS/ft_putchar.c\
		utils/FT_PRINTF_PS/ft_putnbr.c utils/FT_PRINTF_PS/ft_putstr.c\

BONUS_SRC = bonus/checker_bonus.c bonus/moves_bonus.c bonus/r_moves_bonus.c bonus/check_args_bonus.c bonus/check_moves_bonus.c\
		bonus/utils_bonus.c utils/LIBFT_PS/ft_atoi.c utils/LIBFT_PS/ft_isdigit.c\
		utils/LIBFT_PS/ft_split.c utils/LIBFT_PS/ft_nodeadd_back.c utils/LIBFT_PS/ft_newnode.c utils/LIBFT_PS/ft_strncmp.c utils/GET_NEXT_LINE_PS/get_next_line.c\
		utils/GET_NEXT_LINE_PS/get_next_line_utils.c utils/FT_PRINTF_PS/ft_printf.c utils/FT_PRINTF_PS/ft_putchar.c\
		utils/FT_PRINTF_PS/ft_putnbr.c utils/FT_PRINTF_PS/ft_putstr.c\

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS_SRC:.c=.o)

mandatory: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(BONUS_NAME) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_BONUS)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BONUS_NAME)

all : $(NAME) $(BONUS_NAME)

clean :
	rm -f $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean all

.PHONY : all clean fclean re bonus mandatory
