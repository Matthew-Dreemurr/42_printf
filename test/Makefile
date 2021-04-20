# ====================== VARIABLES ====================== #

NAME = libftprintf.a

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror

# ====================== FILES ====================== #

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

SRC = $(notdir $(SRCS))
OBJ = $(SRC:c=o)

# ====================== RULES ====================== #

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $^ -o $@

all: re

refresh:
	cp ../src/*c .

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

re: fclean
	-git clone https://github.com/gavinfielder/pft.git
	make fclean
	make refresh
	make $(NAME)
	make clean
	make -C pft

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out
	rm -rf $(SRC)

clean:
	rm -rf $(OBJ)