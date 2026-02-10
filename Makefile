NAME = fdf
CC = cc
CFLAGS = -Ilibft

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = $(wildcard *.c) \
		$(wildcard utils/*.c) \
		$(wildcard parsing/*.c) \
		$(wildcard libft/*.c) \
		$(wildcard trace/*.c)

OBJS = $(SRCS:.c=.o)

MLX_PATH = minilibx-linux

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -o $(NAME)

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
