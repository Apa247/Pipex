-include vbles.mk

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(DPNDS) $(OBJSBONUS) $(DPNDSBONUS)

fclean: clean
	$(RM) $(NAME)

bonus: $(OBJSBONUS)
	$(AR) $(NAME) $(OBJSBONUS)

re: fclean all

.PHONY: all clean fclean bonus re
