NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = 

OBJ_BONUS = $(SRC:.c=.o)

green = \033[0;32m
red = \033[0;31m

all: bonus

bonus : $(NAME) 

$(NAME) : $(OBJ_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(green) building"

$(OBJ_BONUS) : %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_BONUS)
	@echo "$(red) cleanning"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(red) removing executable"

re : fclean all

.PHONY: all clean fclean re
