NAME = fdf
NAME_BONUS = fdf_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCDIR = includes
INCDIR_BONUS = includes_bonus
OBJDIR = obj
OBJDIR_BONUS = obj_bonus
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

SRCS = $(wildcard src/*.c) \
		$(wildcard src/utils/*.c)
SRCS_BONUS = $(wildcard src_bonus/*.c) \
		$(wildcard src_bonus/utils/*.c)
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJDIR_BONUS)/%.o)

INCLUDES = -I$(INCDIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
INCLUDES_BONUS = -I$(INCDIR_BONUS) -I$(LIBFT_DIR) -I$(MLX_DIR)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

#---------------Mandatory---------------
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#-------------Bonus----------------------
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME_BONUS)

$(OBJDIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

#-------------Library------------------
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

#-------------Commandes-----------------
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJDIR) $(OBJDIR_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re