NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g

SRC = utils/ft_atoi.c utils/ft_isdigit.c src/utils.c src/init_struct.c src/actions.c src/monitoring.c src/main.c

OBJ = $(SRC:.c=.o)

green = \033[0;32m
red = \033[0;31m

all : $(NAME)
$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(green) building"

$(OBJ) : %.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)
	@echo "$(red) cleanning"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(red) removing executable"

re : fclean all

.PHONY: all clean fclean re