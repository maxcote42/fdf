NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = $(wildcard *.c) \
		$(wildcard utils/*.c) \
		$(wildcard parsing/*.c)

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
