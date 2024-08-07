NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
C_FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strlen.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strncpy.c ft_strcpy.c ft_strmapi.c ft_strncmp.c ft_strcmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c ft_printf.c ft_formatspecifier.c ft_char.c \
		ft_hexa.c ft_nbr.c ft_pointer.c ft_str.c ft_unsigned.c ft_calloc.c \
		get_next_line.c get_next_line_utils.c
OBJ_FILES = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SILENT: