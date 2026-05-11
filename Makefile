NAME = a.out

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	get_next_line.c \
		get_next_line_utils.c \
		main.c

OBJS:= $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re