# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemunov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/30 17:15:04 by atemunov          #+#    #+#              #
#    Updated: 2018/07/02 10:09:07 by atemunov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = grimly

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./libft/libft.a

SRC = src/main.c \

OBJ = *.o

READY = @echo "\033[0;32mGrimly Executable ready to use!"

all : $(NAME)

$(NAME):
	@make -C libft/
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) -o $(NAME)
	@echo "Succesfully created FdF Executable"
	$(READY)

clean:
	make -C libft fclean
	make -C mlx clean

fclean:
	rm -rf $(NAME)

re: fclean all
