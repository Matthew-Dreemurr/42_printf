# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 17:20:07 by mhadad            #+#    #+#              #
#    Updated: 2021/03/16 18:50:55 by mhadad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:c=o)
#BONUS = $(SRC_BONUS:c=o)
SRC=

# ================================ RULES ================================= #

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJ)

.PHONY: clean all, clean, fclean, re