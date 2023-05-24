# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdali <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 09:03:17 by mabdali           #+#    #+#              #
#    Updated: 2023/02/20 10:04:40 by mabdali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c\
			ft_hexa.c\
			ft_int.c\
			ft_char.c\
			ft_strlen.c\
			ft_putstr_fd.c\
			ft_putchar_fd.c\
			ft_putnbr_fd.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
    
re: fclean all

.PHONY: all bonus clean fclean re
