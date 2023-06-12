# General Makefile Variables
NAME = cub3d
CC = cc
FLAGS = -Wall -Werror -Wextra -fsanitize=address
SOURCE = $(addprefix SOURCE/, main.c map_loader.c map_loader_support.c map_loader_extra.c string_manipulation.c)

# Libraries
MLX42 = libmlx42.a
LIBFT = libft.a
PRINTF = libftprintf.a
MALLOC = ft_malloc.a

# Sources for the libraries
LIBFT_SRC = $(addprefix libft/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c)
PRINTF_SRC = $(addprefix ft_printf/, ft_printf.c ft_putadress.c ft_putbase_fd.c ft_putbase_fdLower.c ft_putchar_fd.c ft_putnbr_fd.c ft_putnbr_fd_unsigned.c ft_putstr_fd.c)
MALLOC_SRC = $(addprefix ft_malloc/, ft_malloc.c misc_functions.c misc_functions2.c)

# Misc but needed frameworks libraries and includes for MLX
MLX_DEP = -framework Cocoa -framework OpenGL -framework IOKit -L "./libglfw3.a"
INCLUDE = -I MLX42 -I INCLUDES -I libft -I ft_malloc -I ft_printf

.PHONY: re fclean clean all

all: $(LIBFT) $(PRINTF) $(NAME) 

# Norminette
norm:
	norminette SOURCE/ INCLUDES/

$(LIBFT) $(PRINTF) $(MALLOC): $(LIBFT_SRC) $(PRINTF_SRC) $(MALLOC_SRC)
	@make -C libft
	@make -C ft_printf
	@make -C ft_malloc
	@mv ./libft/libft.a ./
	@mv ./ft_printf/libftprintf.a ./
	@mv ./ft_malloc/ft_malloc.a ./

$(NAME): $(SOURCE) $(SOURCE:.c=.o)
	@tput el
	@echo "Making executable: |$@|"
	@$(CC) $(FLAGS) $(SOURCE:.c=.o) $(LIBFT) $(PRINTF) $(MALLOC) $(MLX42) $(MLX_DEP) -o $@

./SOURCE/%.o: ./SOURCE/%.c
	@tput cuu1
	@echo "Creating Object file: |$@|"
	@$(CC) $(FLAGS) $< -c -o $@

clean:
	@rm -rf $(SOURCE:.c=.o)
	@make clean -C ./libft
	@make clean -C ./ft_printf
	@make clean -C ./ft_malloc

fclean: clean
	@rm -rf $(NAME) $(LIBFT) $(PRINTF) $(MALLOC)
	@make fclean -C ./libft
	@make fclean -C ./ft_printf
	@make fclean -C ./ft_malloc

re: fclean all
