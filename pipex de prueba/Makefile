
NAME		= pipex

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_process.c ft_errors.c main.c

OBJS		= $(SRCS:.c=.o)

LIBFT		= Libft/libft.a

all: $(NAME)

$(NAME):	$(OBJS)
	make -C libft/
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
