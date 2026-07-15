NAME       = cub3D

CC         = cc
CFLAGS     = -Wall -Wextra -Werror

ROOT       = ../..
LIBFT_DIR  = $(ROOT)/libft
LIBFT_LIB  = $(LIBFT_DIR)/libft.a
INCLUDES   = -I$(ROOT)/includes -I$(LIBFT_DIR)

OBJ_DIR    = obj

SRCS       = \
	main.c \
	parsing.c \
	tools.c \
	map.c \
	map_check.c \
	map_valid.c \
	element.c \
	element_fill.c \
	rgb.c \
	texture.c \
	flood.c \
	resolver.c

OBJS       = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
