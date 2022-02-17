# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 15:23:37 by rgirondo          #+#    #+#              #
#    Updated: 2021/10/10 19:34:04 by rgirondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

CC=gcc

CFLAGS=-Wall -Wextra -Werror

CMLX=-I /usr/local/include -g -L /usr/local/lib -lmlx \
	-framework OpenGL -framework AppKit

HEADER=./src/so_long.h ./gnl/get_next_line.h ./ft_printf/ft_printf.h

RM=rm -f

SRC= ./src/so_long.c ./gnl/get_next_line.c \
	./gnl/get_next_line_utils.c ./src/ft_split.c ./src/ft_strncmp.c \
	 ./src/error.c ./src/ft_map.c ./src/image.c ./src/move.c

OBJ=$(SRC:%.c=%.o)

all:$(NAME)

$(NAME): $(OBJ) $(HEADER)
		cd ./ft_printf/ && make
		$(CC) $(CFLAGS) $(CMLX) -L ./ft_printf/ -lftprintf\
		-o $(NAME) $(OBJ) 

clean:
		cd ./ft_printf/ && make fclean
		$(RM) $(OBJ)

fclean: clean
		$(RM)
		rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
