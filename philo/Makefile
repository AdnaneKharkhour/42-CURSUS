NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g

SRC = utils/ft_atoi.c utils/ft_isdigit.c utils.c actions.c monitoring.c main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ) : %.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re