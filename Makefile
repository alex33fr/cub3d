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
SRCS        = $(shell find $(SRC_DIR) -name '*.c' 2>/dev/null)
OBJ_DIR     = obj
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
RED   = \033[0;31m
RESET = \033[0m

all:
	@printf "\r$(GREEN)[  0%%] Initialisation$(RESET)"
	@$(MAKE) $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	@printf "\r$(GREEN)[ 90%%] Edition des liens$(RESET)          "
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME) \
	|| (printf "\n$(RED)Erreur edition des liens$(RESET)\n"; exit 1)
	@printf "\r$(GREEN)[100%%] Build termine : $(NAME)$(RESET)\n"

$(MLX_LIB):
	@printf "\r$(GREEN)[ 10%%] MinilibX$(RESET)                   "
	@if [ ! -d "$(MLX_DIR)" ]; then \
		if [ ! -f "$(MLX_ARCHIVE)" ]; then \
			curl -L $(MLX_URL) -o $(MLX_ARCHIVE) || wget $(MLX_URL); \
		fi; \
		tar -xzf $(MLX_ARCHIVE); \
	fi
	@$(MAKE) -C $(MLX_DIR) >/dev/null 2>&1 \
	|| (printf "\n$(RED)Erreur compilation MinilibX$(RESET)\n"; exit 1)

$(LIBFT_LIB):
	@printf "\r$(GREEN)[ 40%%] Libft$(RESET)                       "
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1 \
	|| (printf "\n$(RED)Erreur compilation Libft$(RESET)\n"; exit 1)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "\r$(GREEN)[ 70%%] %s$(RESET)                      " "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ \
	|| (printf "\n$(RED)Erreur compilation %s$(RESET)\n" "$<"; exit 1)

clean:
	@rm -rf $(OBJ_DIR)
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1; fi
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1
	@printf "$(GREEN)[OK] Nettoyage termine$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null 2>&1
	@printf "$(GREEN)[OK] Fclean termine$(RESET)\n"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
