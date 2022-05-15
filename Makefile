NAME = philo

BONUS = philo_bonus

HEADER = philo.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = philo.c \
		./src_philo/ft_check.c \
		./src_philo/ft_read_args.c \

OBJ = $(SRC:%.c= %.o)

.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -O2 $(OBJ) -o $(NAME)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus :  $(BONUS)

$(BONUS) : $(OBJ_BONUS) $(HEADER)
	$(CC) $(FLAGS) -O2 $(OBJ_BONUS) -o $(BONUS)

clean	:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)

fclean	:	clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)

re	:	fclean all