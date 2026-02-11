NAME = fdf
CC = cc

MLX_PATH = minilibx-linux
LIBFT_PATH = libft

CFLAGS = -Wall -Wextra -Werror \
         -I$(LIBFT_PATH) \
         -Iincludes \
         -I$(MLX_PATH)

LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

SRCS = $(wildcard *.c) \
       $(wildcard src/*.c) \
       $(wildcard src/utils/*.c)

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) \
		-L$(LIBFT_PATH) -lft \
		-L$(MLX_PATH) -lmlx -lXext -lX11 -lm \
		-o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re