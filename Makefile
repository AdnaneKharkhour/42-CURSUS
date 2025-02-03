NAME = push_swap

BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRC = push_swap.c src/utils.c src/check_args.c src/sort_less_than_five.c src/sort.c src/moves.c\
	src/r_moves.c LIBFT/ft_atoi.c LIBFT/ft_isdigit.c LIBFT/ft_split.c\
	LIBFT/ft_nodeadd_back.c LIBFT/ft_newnode.c FT_PRINTF/ft_printf.c FT_PRINTF/ft_putchar.c\
		FT_PRINTF/ft_putnbr.c FT_PRINTF/ft_putstr.c\

BONUS_SRC = bonus/checker.c bonus/moves_bonus.c bonus/r_moves_bonus.c bonus/check_args_bonus.c bonus/check_moves_bonus.c bonus/sort_bonus.c \
		bonus/sort_less_than_five_bonus.c bonus/utils_bonus.c LIBFT/ft_atoi.c LIBFT/ft_isdigit.c\
		LIBFT/ft_split.c LIBFT/ft_nodeadd_back.c LIBFT/ft_newnode.c LIBFT/ft_strncmp.c GET_NEXT_LINE/get_next_line.c \
		GET_NEXT_LINE/get_next_line_utils.c FT_PRINTF/ft_printf.c FT_PRINTF/ft_putchar.c\
		FT_PRINTF/ft_putnbr.c FT_PRINTF/ft_putstr.c\

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS_SRC:.c=.o)

mandatory: $(NAME)

$(NAME) : $(OBJ) push_swap.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(BONUS_NAME) : $(OBJ_BONUS) bonus/checker_bonus.h
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_BONUS)

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
