CC = cc
FLAGS = -fsanitize=address -g
NAME = cub

SRC =	cub.c\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\
		\


%.o: %.c
	$(CC) -c  -o $@ $<

OBJ = $(SRC:%.c=%.o)



all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC)  libmlx42.a -Iinclude -lglfw $(OBJ) -o $(NAME)

fclean :
	@rm -rf $(OBJ) $(NAME)

clean :
	@rm -rf $(OBJ)

re : fclean all