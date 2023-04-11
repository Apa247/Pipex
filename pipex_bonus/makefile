# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 19:54:49 by daparici          #+#    #+#              #
#    Updated: 2023/04/11 12:31:40 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra# -g -fsanitize=address -g3
AR = ar rcs

SRCS = pipex_bonus.c pipex_utils_bonus.c pipex_bonus_process.c

LIBFT = ./Libft/libft.a

PRINTF = ./printf/libftprintf.a

GNL = get_next_line.c get_next_line_utils.c
GNLPATH = $(addprefix ./GetNextLine/,$(GNL))

OBJS = ${SRCS:.c=.o}
GNLOBJ = $(GNLPATH:.c=.o)

$(NAME): $(OBJS) $(GNLOBJ)
		make bonus -C ./Libft;
		make -C ./printf;
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNLOBJ) $(PRINTF) -o $(NAME)
all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
	make fclean -C ./Libft;
	make fclean -C ./printf;
re: clean all
.PHONY: bonus all clean fclean re