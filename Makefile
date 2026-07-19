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

INCLUDES  = -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR)

OBJ_DIR   = obj

GREEN = \033[0;32m
BLUE  = \033[0;34m
RED   = \033[0;31m
RESET = \033[0m

SRCS =	src/main.c \
		src/cleanup/cleanup_game.c \
		src/cleanup/cleanup_mlx.c \
		src/events/hooks.c \
		src/init/mlx_init.c \
		src/render/render.c \
		src/utils/color.c \
		src/utils/img.c \
		src/bridge/scene_map.c \
		src/bridge/scene_fill.c \
		src/render/ray_init.c \
		src/render/ray_dda.c \
		src/utils/map_guard.c \
		src/init/textures_load.c \
		src/texture/texture_face.c \
		src/texture/draw_texture.c \
		src/player/move.c \
		src/player/rotate.c \
		src/events/input.c \
		src/parsing/parsing.c \
		src/parsing/tools.c \
		src/parsing/map.c \
		src/parsing/map_check.c \
		src/parsing/map_valid.c \
		src/parsing/element.c \
		src/parsing/element_fill.c \
		src/parsing/rgb.c \
		src/parsing/texture.c \
		src/parsing/flood.c \
		src/parsing/resolver.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "$(GREEN)[Compiling]$(RESET) $<\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ || (printf "$(RED)Error in $<$(RESET)\n"; exit 1)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -no-pie -o $(NAME) || (printf "$(RED)Link error$(RESET)\n"; exit 1)
	@rm -f $(MLX_ARCHIVE)
	@printf "$(GREEN)[100%%] ========[ $(NAME) is ready ]======== [OK]$(RESET)\n"

$(MLX_LIB):
	@printf "$(GREEN)[cub3D]$(RESET)\n"
	@if [ ! -d "$(MLX_DIR)" ]; then \
		if [ ! -f "$(MLX_ARCHIVE)" ]; then \
			curl -L $(MLX_URL) -o $(MLX_ARCHIVE) || wget $(MLX_URL); \
		fi; \
		tar -xzf $(MLX_ARCHIVE); \
	fi
	@$(MAKE) -C $(MLX_DIR) >/dev/null 2>&1; \
	if [ ! -f "$(MLX_LIB)" ]; then \
		printf "$(RED)MinilibX compilation error$(RESET)\n"; exit 1; \
	fi

$(LIBFT_LIB):
	@printf "$(GREEN)[Libft]$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1 || (printf "$(RED)Libft compilation error$(RESET)\n"; exit 1)

clean:
	@rm -rf $(OBJ_DIR)
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1; fi
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1; fi
	@printf "$(GREEN)Clean [OK]$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR)
	@rm -f $(MLX_ARCHIVE)
	@printf "$(GREEN)Fclean [OK]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
