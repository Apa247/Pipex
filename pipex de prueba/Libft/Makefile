# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 19:06:51 by mgonzale          #+#    #+#              #
#    Updated: 2022/03/29 12:59:46 by mgonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strdup.c ft_split.c ft_strncmp.c ft_strjoin.c ft_strnstr.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re bonus
