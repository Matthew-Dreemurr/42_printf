# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 17:20:07 by mhadad            #+#    #+#              #
#    Updated: 2021/04/20 15:03:16 by mhadad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ====================== VARIABLES ====================== #

NAME = libftprintf.a

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror

SHELL=/bin/bash
BRANCH=origin/ft_printf_V1

DEF = $(SANI) $(BR) $(DEBUG) $(WRA)

BR = -D BREAK_PAUSE=0
DEBUG = -D DEBUG_UTILS_H
WRA = -D WRALOC_H
SANI = -fsanitize=address
TIMEOUT = timeout 0.05

# ====================== FILES ====================== #

OBJ_DIR = bin/
SRC_DIR = src/

SRCS = \
src/arg_hex.c \
src/arg_alpha.c \
src/convert.c \
src/print_alpha.c \
src/ft_printf.c \
src/dummy.c \
src/len_utils.c \
src/width.c \
src/flag_manager.c \
src/print_num.c \
src/print_manager.c \
src/arg_num.c \
src/parser.c 

SRC := $(notdir $(SRCS))
OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_DIR), $(OBJ))
# ====================== RULES ====================== #

all: $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEF) -I include -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $<
	@cat _src/compile_ok

re: fclean all

exe: main
	@echo "\n"
	$(TIMEOUT) ./a.out
	
main: re
	$(CC) $(CFLAGS) $(DEF) main.c libftprintf.a

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C test
	rm -rf a.out

clean:
	rm -rf $(OBJS)

c:
	@clear

nrm:
	norminette src/*.c include/ft_printf.h

git:
	@git pull
	@-git add .
	@git commit -am "Makefile push `date +'%Y-%m-%d %H:%M:%S'`"
	@-git push

fgit:
	@printf "\033[31;1m ======== /!\\ Hard reset Git /!\\ ======== \033[0m\n"
	@while true; do read -p "continue [y/N] ? " resp; if [[ $$resp =~ ^[Yy]$$ ]]; then exit 0; else exit 1; fi; done
	@git fetch --all
	@git reset --hard $(BRANCH)
	@git clean -f

test:
	$(MAKE) re -C test

testc:
	$(MAKE) fclean -C test
.PHONY: clean all, clean, fclean, re, git, fgit, test