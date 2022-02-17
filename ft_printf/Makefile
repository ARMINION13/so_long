# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 15:23:37 by rgirondo          #+#    #+#              #
#    Updated: 2021/09/16 20:43:13 by rgirondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC= *.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): ft_printf.h
		$(CC) $(CFLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		$(RM) $(OBJ) $(OBJ2)

fclean: clean
		$(RM)
		rm *.a

re: fclean all

.PHONY: all clean fclean re
