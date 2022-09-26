# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 13:43:23 by jpizarro          #+#    #+#              #
#    Updated: 2022/03/01 05:35:42 by jpizarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

SRCS = ft_atoi.c ft_bchar.c ft_bzero.c ft_calloc.c ft_charindex.c ft_charlloc.c ft_charpos.c ft_free_split.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c ft_itoa_base.c ft_litoa_base.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnewline.c ft_strnlen.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_uitoa.c ft_wordcount.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

all:		$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	@ar -rcs $@ $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean:		clean
	@$(RM) $(NAME)

re:	fclean all
