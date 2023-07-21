# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:42:43 by hmeftah           #+#    #+#              #
#    Updated: 2023/06/11 17:10:38 by hmeftah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS =  -Wall -Wextra -Werror

SRC = ft_printf.c ft_putadress.c ft_putbase_fd.c ft_putbase_fdLower.c ft_putchar_fd.c ft_putnbr_fd.c \
	  ft_putnbr_fd_unsigned.c ft_putstr_fd.c
	  
OBJECTS = $(SRC:.c=.o)

INCLUDE = ./ft_printf.h

all : $(NAME)

$(NAME) : $(OBJECTS)
	@ar -r $(NAME) $(OBJECTS)

%.o : %.c
	@$(CC) $(FLAGS) -I $(INCLUDE) -c $<

clean : 
	@rm -f $(OBJECTS)
fclean : clean
	@rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re