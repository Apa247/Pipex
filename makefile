# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 13:59:15 by daparici          #+#    #+#              #
#    Updated: 2023/04/11 12:39:00 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra# -g -fsanitize=address -g3
AR = ar rcs

SRCS = pipex.c pipex_utils.c 

LIBFT = ./Libft/libft.a

PRINTF = ./printf/libftprintf.a

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
		make bonus -C ./Libft;
		make -C ./printf;
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
	make fclean -C ./Libft;
	make fclean -C ./printf;
re: clean all
.PHONY: bonus all clean fclean re