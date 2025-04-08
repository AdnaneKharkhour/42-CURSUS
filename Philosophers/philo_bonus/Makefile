NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g

SRC = utils_bonus/ft_atoi_bonus.c utils_bonus/ft_isdigit_bonus.c src_bonus/utils_bonus.c \
	src_bonus/init_struct_bonus.c src_bonus/actions_bonus.c src_bonus/monitoring_bonus.c src_bonus/main_bonus.c

OBJ = $(SRC:.c=.o)

green = \033[0;32m
red = \033[0;31m

all : $(NAME)
$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(green) building"

$(OBJ) : %.o: %.c philo_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)
	@echo "$(red) cleanning"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(red) removing executable"

re : fclean all

.PHONY: all clean fclean re