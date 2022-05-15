# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncallie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 13:39:51 by ncallie           #+#    #+#              #
#    Updated: 2021/10/23 17:31:44 by ncallie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC =	ft_printf.c			\
		check_flag.c		\
		check_descript.c	\
		is_char.c			\
		is_hex_p1.c			\
		is_hex_hex.c		\
		is_hex_point.c		\
		is_number.c			\
		is_pointer.c		\
		is_str.c			\
		is_unsig_num.c		\
		nbr_count.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ) 
	ar rc $(NAME) $?
	ranlib $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean  all

.PHONY: all clean fclean re