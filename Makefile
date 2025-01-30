NAME = push_swap
NAME_BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC = push_swap.c utils.c check_args.c LIBFT/ft_atoi.c LIBFT/ft_isdigit.c LIBFT/ft_isalpha.c LIBFT/ft_strlen.c LIBFT/ft_split.c LIBFT/ft_nodeadd_back.c LIBFT/ft_newnode.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
