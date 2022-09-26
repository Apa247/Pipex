# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 11:24:00 by jpizarro          #+#    #+#              #
#    Updated: 2022/03/02 07:11:41 by jpizarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean debug fclean re run show

NAME = pipex

SRCS =	srcs/data_init.c srcs/error_exit.c srcs/exec_cmd.c srcs/exec_cmds.c srcs/get_env_path.c srcs/get_files.c srcs/get_path.c srcs/perror_exit.c srcs/pipex.c srcs/search_path.c

CHECK = srcs/check_argc.c

CHECK-BON = srcs/check_argc_bonus.c

OBJS = $(SRCS:.c=.o) $(CHECK:.c=.o)

OBJS-BON = $(SRCS:.c=.o) $(CHECK-BON:.c=.o)

LIBS = libft/libft.h

STATICS = $(LIBS:.h=.a)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(STATICS)
	@echo "Creating $@"
	$(CC) $(CFLAGS) $(OBJS) $(STATICS) -o $@
	@echo "$@ is ready!"

bonus: $(OBJS-BON) $(STATICS)
	@echo "Creating $@"
	$(CC) $(CFLAGS) $(OBJS-BON) $(STATICS) -o $(NAME)
	@echo "$@ is ready!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(STATICS):
	cd libft/ && $(MAKE)

clean:
	@echo "Cleaing up binary files"
	$(RM) $(OBJS)
	cd libft/ && $(MAKE) $@

fclean: clean
	@echo "also $(NAME), debug and .bmp files"
	$(RM) $(NAME) debug
	$(RM) $(wildcard srcs/*.o)
	$(RM) $(wildcard *.out)
	cd libft/ && $(MAKE) $@

re: fclean all

rebonus: fclean bonus

debug: fclean $(OBJS) $(STATICS)
	@echo "Creating $@ file"
	$(CC) -g $(OBJS) $(STATICS) -o $@
	@echo "$@ is ready!"

show:
	@echo "SRCS $(SRCS)"
	@echo "CHECK $(CHECK)"
	@echo "CHECK-BON $(CHECK-BON)"
	@echo "OBJS $(OBJS)"
	@echo "OBJS-BON $(OBJS-BON)"
	@echo "LIBS $(LIBS)"
	@echo "STATICS $(STATICS)"
	