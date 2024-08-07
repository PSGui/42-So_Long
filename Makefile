# NAME = so_long
# CC = cc -g -Wall -Wextra -Werror
# RM = rm -rf
# LIBFT = libft/libft.a
# LIBFT_DIR = libft/
# MLX_DIR = ./mlx
# MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
# MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

# FILES = 1_start_map.c 2_start_window.c 3_load_images.c 4_check_map.c 5_place_sprites.c \
#  6_hook_handler.c 7_movements.c 8_movements_check.c so_long.c stop_game.c
# SRCS = $(addprefix source/, $(FILES))

# OBJS = $(SRCS:.c=.o)
# INCLUDES = -I/usr/include -Imlx

# all:  $(MLX_LIB) $(NAME)

# $(NAME): $(LIBFT) $(OBJS)
# 	$(CC) -o $(NAME) $(LIBFT) $(MLX_FLAGS) $(OBJS)

# $(MLX_LIB):
# 	@make -C $(MLX_DIR) --no-print-directory

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR) --no-print-directory

# $(OBJS): $(SRCS)
# 	$(CC) -c $< -o $@ $(INCLUDES)

# clean:
# 	$(RM) $(OBJS)
# 	$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory

# fclean: clean
# 	$(RM) $(NAME)
# 	$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory

# re: fclean
# 	$(MAKE)

# .SILENT:


#	====================		Directories		====================

SOURCES = source
HEADERS = includes
OBJECTS_DIRECTORY = objects
LIBFT = libft/libft.a
LIBFT_DIR = libft/
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

#	====================		Files      		====================

NAME = so_long

FILES = so_long.c 1_start_map.c 2_start_window.c 3_load_images.c 4_check_map.c \
 5_place_sprites.c 6_hook_handler.c 7_movements.c 8_movements_check.c stop_game.c

OBJECTS = $(addprefix source/, $(FILES:.c=.o))

#	====================		Flags      		====================

CC = cc

I = -I $(HEADERS)

INCLUDES = -I/usr/include -Imlx

CFLAGS = -g -Wall -Wextra -Werror 

WBLOCK = --no-print-directory

RM = rm -rf

#	====================		Colors     		====================

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
CYAN = \033[0;36m

B_RED = \033[1;31m
B_GREEN = \033[1;32m
B_BLUE = \033[1;34m
L_BLUE = \033[1;94m
B_YELLOW = \033[1;33m
B_MAGENTA = \033[1;35m
B_CYAN = \033[1;36m

RESET = \033[0m

#	====================		Rules      		====================

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(LIBFT) $(OBJECTS)
	echo "[$(CYAN)Executable$(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME) -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES)/%.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) $(I) -c $< -o $@

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJECTS)
	echo $(OBJECTS)
	echo "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) binary files deleted$(RESET)"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	echo "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) deleted$(RESET)"

re: fclean all
	clear

leak: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps_example/teste.ber

.PHONY: all clean fclean re leak
.SILENT: