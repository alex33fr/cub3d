NAME       = parsing

CC         = cc
CFLAGS     = -Wall -Wextra -Werror -g

ROOT       = ../..
LIBFT_DIR  = $(ROOT)/libft
LIBFT_LIB  = $(LIBFT_DIR)/libft.a
INCLUDES   = -I$(ROOT)/includes -I$(LIBFT_DIR)

SRCS       = \
	main.c \
	parsing.c

OBJS       = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
