NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -I./libft

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = main.c \
	parse_flags.c \
	compute_disorder.c \
	parse_nums.c \
	bench.c \
	strategies/sort_simple.c \
	strategies/sort_medium.c \
	strategies/sort_medium_utils.c \
	strategies/sort_complex.c \
	strategies/sort_adaptive.c \
	operations/swap.c \
	operations/push.c \
	operations/rotate.c \
	operations/reverse_rotate.c \


OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

# Libft dizinindeki Makefile'ı tetikler [1]
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Push_swap ikilisini derler ve libft.a ile bağlar [1]
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re