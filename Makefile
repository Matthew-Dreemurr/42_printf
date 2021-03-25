# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 17:20:07 by mhadad            #+#    #+#              #
#    Updated: 2021/03/25 16:14:07 by mhadad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME = libftprintf.a

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
DEF = $(SANI) $(BRK) $(DEBUG) $(WRA)
BRK = -D BREAK_PAUSE=0
DEBUG = -D DEBUG_UTILS_H
WRA = -D WRALOC_H
SANI = -fsanitize=address

# --- files --- #

SRC= \
src/ft_printf.c \
src/utils1.c \
src/convert.c

OBJ = $(SRC:c=o)

# ================================ RULES ================================= #

%.o: %.c
	$(CC) $(CFLAGS) $(DEF) -I include -c $^ -o $@

all: $(NAME)
	@cat _src/compile_ok

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

re: fclean all

exe: main
	@echo "\n"
	@./a.out
	
main: re
	@$(CC) $(CFLAGS) $(DEF) main.c libftprintf.a


fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJ)

c:
	@clear
nrm:
	norminette src/*.c include/ft_printf.h
git:
	@-git pull
	@-git add .
	@-git commit -am "auto"
	@-git push
.PHONY: clean all, clean, fclean, re, git