NAME = philo

BONUS = philo_bonus

HEADER = philo.h

CC = gcc

FLAGS = -Wall -Wextra -Werror# -fsanitize=thread -g

SRC = philo.c \
		./src_philo/ft_atoi.c \
		./src_philo/ft_check.c \
		./src_philo/ft_check_living.c \
		./src_philo/ft_cycle.c \
		./src_philo/ft_dinner.c \
		./src_philo/ft_if_alive.c \
		./src_philo/ft_print_error.c \
		./src_philo/ft_process_threads.c \
		./src_philo/ft_read_args.c \
		./src_philo/ft_simulation.c \
		./src_philo/ft_time.c

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