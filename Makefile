NAME        = cub3D

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_ARCHIVE = minilibx-linux.tgz
MLX_URL     = https://cdn.intra.42.fr/document/document/54644/minilibx-linux.tgz
MLX_FLAGS   = $(MLX_DIR)/libmlx.a -lX11 -lXext -lm -lz

LIBFT_DIR   = libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

INCLUDES    = -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR)

SRC_DIR     = src
OBJ_DIR     = obj
SRCS        = $(shell find $(SRC_DIR) -name '*.c' 2>/dev/null)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		curl -L $(MLX_URL) -o $(MLX_ARCHIVE) || wget $(MLX_URL); \
		tar -xzf $(MLX_ARCHIVE); \
	fi
	@$(MAKE) -C $(MLX_DIR) >/dev/null 2>&1
src/parsing/main.c
$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@[ -d "$(MLX_DIR)" ] && $(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1 || true
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1 || true

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR) $(MLX_ARCHIVE)
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null 2>&1 || true

re: fclean all

.PHONY: all clean fclean re
