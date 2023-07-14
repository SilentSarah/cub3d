CC = gcc
FLAGS = -Wall -Werror -Wextra
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


%.o: %.c %.h
	$(CC) -c  -o $@ $<

OBJ = $(SRC:%.c=%.o)



all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC)    libmlx42.a -Iinclude -lglfw $(OBJ) -o $(NAME)

fclean :
	@rm -rf $(BOBJ) $(OBJ) $(NAME) $(BNAME)

clean :
	@rm -rf $(OBJ) $(BOBJ)

re : fclean all