# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemunov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/22 22:33:49 by atemunov          #+#    #+#              #
#    Updated: 2018/07/22 22:33:52 by atemunov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = grimly

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./libft/libft.a

SRC = src/main.c \
	src/get_maze.c \
	src/dfs.c \
	src/print_maze.c 

OBJ = *.o

READY = @echo "\033[0;32mGrimly Executable ready to use!"

all : $(NAME)

$(NAME):
	@make -C libft/
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) -o $(NAME)
	$(READY)

clean:
	make -C libft fclean
	make -C mlx clean

fclean:
	rm -rf $(NAME)

re: fclean all
