NAME = cub3d
CC = cc
FLAGS = -Wall -Werror -Wextra
SOURCE = $(addprefix SOURCE/, main.c)
MLX42 = libmlx42.a
LIBFT = libft.a
LIBFT_SRC = $(addprefix libft/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c)
MLX_DEP = -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/hmeftah/goinfre/homebrew/Cellar/glfw/3.3.8/lib"
INCLUDE = -I MLX42 -I INCLUDES -I libft
DEBUG_F = -g -fdiagnostics-color=always

.PHONY: re fclean clean all

all: $(LIBFT) $(NAME) 
norm:
	norminette SOURCE/ INCLUDES/

$(LIBFT): $(LIBFT_SRC)
	@make -C libft
	@mv ./libft/libft.a ./

$(NAME): $(SOURCE) $(SOURCE:.c=.o)
	@tput el
	@echo "Making executable: |$@|"
	@$(CC) $(FLAGS) $(SOURCE:.c=.o) $(LIBFT) $(MLX42) $(MLX_DEP) $(DEBUG_F) -o $@

./SOURCE/%.o: ./SOURCE/%.c
	@tput cuu1
	@echo "Creating Object file: |$@|"
	@$(CC) $(FLAGS) $(INCLUDE) $< -c -o $@

clean:
	@rm -rf $(SOURCE:.c=.o)
	@make clean -C ./libft

fclean: clean
	@rm -rf $(NAME) $(LIBFT)
	@make fclean -C ./libft

re: fclean all
