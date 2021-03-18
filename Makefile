# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 17:20:07 by mhadad            #+#    #+#              #
#    Updated: 2021/03/18 15:33:55 by mhadad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC= \
src/ft_printf.c \
src/utils1.c

OBJ = $(SRC:c=o)

# ================================ RULES ================================= #

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $^ -o $@

all: $(NAME)
	@cat _src/compile_ok

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

re: fclean all

exe: all
	@gcc main.c libftprintf.a
	@echo "\n"
	@./a.out

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJ)

c:
	@clear
nrm:
	norminette src/*.c include/ft_printf.h
.PHONY: clean all, clean, fclean, re