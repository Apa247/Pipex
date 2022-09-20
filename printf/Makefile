# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 10:24:25 by daparici          #+#    #+#              #
#    Updated: 2022/04/20 19:46:02 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = gcc -c
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

SRCS = ft_print_adress_hex_nbr.c ft_printf.c

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

	
all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME) 
re: clean all
.PHONY: bonus all clean fclean re

