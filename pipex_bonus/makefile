# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 19:54:49 by daparici          #+#    #+#              #
#    Updated: 2022/09/27 19:54:59 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra# -g -fsanitize=address -g3
AR = ar rcs

SRCS = 

LIBFT = ./Libft/libft.a

PRINTF = ./printf/libftprintf.a

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
		make bonus -C ./Libft;
		make bonus -C ./printf;
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: clean all
.PHONY: bonus all clean fclean re